/* Copyright (c) 2023 GSI Helmholtzzentrum fuer Schwerionenforschung, Darmstadt
 * SPDX-License-Identifier: GPL-3.0-only
 * Authors: Frederic Linz [committer] */

/** @file Config.cxx
 ** @author Frederic Linz <f.linz@gsi.de>
 ** @date 18.07.2023
 **/

#include "Config.hpp"

#include <fstream>

#include <yaml-cpp/yaml.h>
#include <iostream>

using std::string;

namespace AnalysisTree::QA
{
  

  // ----- Load settings from YAML file ----------
  void Config::LoadYaml(const string& fileName)
  {
    std::cout << "Config: Reading configuration from " << fileName << std::endl;
    YAML::Node settings = YAML::LoadFile(fileName);

    // --- Global settings
    // f_some_name = settings["global"]["varname"]
    

    // --- QA settings
    // f_some_name = settings["qa"]["varname"]
    
    // --- Enabled Tasks
    f_task_default = settings["task"]["default"].as<bool>();

  }
  // ---------------------------------------------


  // ----- Save settings to YAML node ------------
  YAML::Node Config::ToYaml()
  {
    YAML::Node settings;

    // --- Global settings
    //settings["global"]["varname"] = f_some_name;


    return settings;
  }
  // ---------------------------------------------

}  // namespace AnalysisTree::QA
