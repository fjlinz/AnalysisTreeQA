/* Copyright (c) 2023 GSI Helmholtzzentrum fuer Schwerionenforschung, Darmstadt
 * SPDX-License-Identifier: GPL-3.0-only
 * Authors: Frederic Linz [committer] */

/** @file Run.h
 ** @author Frederic Linz <f.linz@gsi.de>
 ** @date 18.07.2023
 **/

#ifndef ANALYSISTREEQA_STEER_RUN_H
#define ANALYSISTREEQA_STEER_RUN_H 1


#include "AnalysisTree/TaskManager.hpp"
#include "Task.hpp"

#include <TNamed.h>
#include <TTree.h>

#include <string>

#include "Config.hpp"


namespace AnalysisTree::QA{


  class Run : public TNamed {

    public:
      /** @brief Constructor **/
      Run();

      /** @brief Destructor **/
      virtual ~Run();

      /** @brief Add a task to the run **/
//      void AddTask(AnalysisTree::QA::Task* task);
      void AddTask(Task* task);

      /** @brief Allow overwriting if output file already exists **/
      void AllowOverwrite() { fOverwrite = true; }

      /** @brief Run QA **/
      void Exec();

      /** @brief Configuration object **/
      const Config& GetConfig() const { return fConfig; }

      /** @brief Set configuration file name
       ** @param fileName Configuration file name **/
      void LoadConfig(const char* fileName);

      /** @brief Set configuration
       ** @param fileName Configuration object **/
      void SetConfig(const Config& config) { fConfig = config; }

      /** @brief Set input file name
       ** @param fileName Input file name **/
      void SetInput(const char* fileName) { fInput = fileName; }

      /** @brief Set output file name
       ** @param fileName Output file name **/
      void SetOutput(const char* fileName) { fOutput = fileName; }

    
    private:
      /** @brief Copy constructor forbidden **/
      Run(const Run&) = delete;

      /** @brief Assignment operator forbidden **/
      Run operator=(const Run&) = delete;

      /** @brief Check existence of a file
       ** @param fileName File name (absolute or relative to current directory)
       ** @return true if file exists **/
      bool CheckFile(const char* fileName);

      /** @brief Create the QA task topology (chain) **/
      void CreateTopology();

    private:
      AnalysisTree::TaskManager* fMan = AnalysisTree::TaskManager::GetInstance();
      std::string fInput = "";
      std::string fOutput = "";
      bool fOverwrite = false;

      Config fConfig = {};
  };

}  // namespace AnalysisTree::QA

#endif /* ANALYSISTREEQA_STEER_RUN_H */
