/* Copyright (c) 2023 GSI Helmholtzzentrum fuer Schwerionenforschung, Darmstadt
 * SPDX-License-Identifier: GPL-3.0-only
 * Authors: Frederic Linz [committer] */

/** @file Application.cpp
 ** @author Frederic Linz <f.linz@gsi.de>
 ** @date 18.07.2023
 **/

#include "Application.hpp"

#include "Config.hpp"

using std::string;

namespace AnalysisTree::QA
{

  // -----  Constructor -------
  Application::Application(ProgramOptions const& opt) : fOpt(opt) {}
  // --------------------------


  // -----  Run QA ------------
  void Application::Exec()
  {
    // --- Use program options
    fRun.SetInput(fOpt.InputFile().c_str());
    fRun.SetOutput(fOpt.OutputFile().c_str());
    if (fOpt.Overwrite()) fRun.AllowOverwrite();


    // --- Read configuration from yaml file
    AnalysisTree::QA::Config config;
    config.LoadYaml(fOpt.ConfigFile());
    fRun.SetConfig(config);


    // --- Execute QA
    fRun.Exec();
  }
}  // namespace AnalysisTree::QA
