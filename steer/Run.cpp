/* Copyright (c) 2023 GSI Helmholtzzentrum fuer Schwerionenforschung, Darmstadt
 * SPDX-License-Identifier: GPL-3.0-only
 * Authors: Frederic Linz [committer] */

/** @file Run.cxx
 ** @author Frederic Linz <f.linz@gsi.de>
 ** @date 18.07.2023
 **/

#include "Run.hpp"

#include "Task.hpp"

#include "TaskFactory.hpp"
#include <TFile.h>
#include <TStopwatch.h>
#include <TString.h>
#include <TTree.h>

#include <cassert>
#include <iostream>

#include <sys/stat.h>

namespace AnalysisTree::QA
{

  // -----  Constructor  ----------
  Run::Run() : TNamed("Run", "AnalysisTreeQA Run") {}
  // ------------------------------
  
  
  // -----  Destructor  -----------
  Run::~Run() { std::cout << "Destructing " << fName << std::endl; }
  // ------------------------------
  

  // -----  Add a QA task  --------
//  void Run::AddTask(AnalysisTree::QA::Task* task)
  void Run::AddTask(Task* task)
  {
    fMan->AddTask(task);
    std::cout << GetName() << ": Added task " << " add function in ATQA!" << std::endl;  //<< task->GetName();
  } 
  // ------------------------------
  
  
  // -----  Check existance of file  -----
  bool Run::CheckFile(const char* fileName)
  {
    struct stat buffer;
    return (stat(fileName, &buffer) == 0);
  }
  // -------------------------------------
  
  
  // -----  Create Topology -------------
  void Run::CreateTopology()
  {
    TaskFactory fact(this);

    auto* task = new AnalysisTree::QA::Task;
    task->SetOutputFileName(fOutput.data());

    // Here all the QA task have to be set
    if (fConfig.f_task_default) fact.RegisterDefaultHistograms(*task);

    fMan->AddTask(task);
  }
  // ------------------------------------
  

  // -----  Execute QA run --------------
  void Run::Exec()
  {
    // --- Mirror options and configuration
    std::cout << GetName() << ": Input file is     " << fInput << std::endl;
    std::cout << GetName() << ": Output file is    " << fOutput << std::endl;
    std::cout << "Configuration:\n" << fConfig.ToString() << std::endl;

    // --- Timer
    TStopwatch timer;
    timer.Start();

    // --- Run info
//    fMan.SetGenerateRunInfo(true);  // Some run infos have to be added to AT(QA)

    // --- Check input and output files
    if (!CheckFile(fInput.data())) throw std::runtime_error("Input file does not exist");
    if (CheckFile(fOutput.data()) && !fOverwrite) throw std::runtime_error("Output file already exists");

    // --- Topology of QA Tasks
    std::cout << GetName() << ": Creating topology..." << std::endl;
    CreateTopology();

    // --- Initialization
    std::cout << GetName() << ": Initialize AnalysisTree::TaskManager..." << std::endl;
    fMan->Init({fInput}, {"rTree"});
    timer.Stop();
    double timeInit = timer.RealTime();
    timer.Start();

    // --- Execute Run
    std::cout << std::endl;
    std::cout << GetName() << ": Starting run" << std::endl;
    fMan->Run(-1);  // use nEvents here and read from config.yaml
    fMan->Finish();

    // --- Finish
    timer.Stop();
    double timeExec = timer.RealTime();
    std::cout << std::endl;
    std::cout << GetName() << ": Execution successful" << std::endl;
    std::cout << GetName() << ": Input file was     " << fInput << std::endl;
    std::cout << GetName() << ": Output file is     " << fOutput << std::endl;
    std::cout << GetName() << ": Execution time: Init " << timeInit << "s, Exec " << timeExec << "s" << std::endl;
  }
  // -------------------------------------
  

  // -----  Read configuration from YAML file --------------------
  void Run::LoadConfig(const char* fileName)
  {
    std::string file(fileName);
//    if (file.IsNull()) {
//      file = std::getenv("VMCWORKDIR");
//      file += "/path-to-config/config/config.yaml";
//    }
    std::cout << GetName() << ": Loading configuration from " << file << std::endl;
    fConfig.LoadYaml(file.data());
  }

} // namespace AnalysisTree::QA
