/* Copyright (c) 2023 GSI Helmholtzzentrum fuer Schwerionenforschnug, Darmstadt
 * SPDX-License-Identifier: GPL-3.0-only
 * Authors: Frederic Linz [committer] */

/** @file Config.h
 ** @author Frederic Linz <f.linz@gsi.de>
 ** @date 18.07.2023
 **
 ** Code taken from reco/offline/steer/Config.h
 **/

#ifndef ANALYSISTREEQA_STEER_CONFIG_H
#define ANALYSISTREEQA_STEER_CONFIG_H 1


#include <array>
#include <fstream>
#include <sstream>
#include <string>

#include <yaml-cpp/yaml.h>

namespace AnalysisTree::QA
{

  /** @class Config
   ** @author Frederic Linz <f.linz@gsi.de>
   ** @date 18.07.2023
   ** 
   ** Configuration for AnalysisTreeQA with interfaces to YAML
   **/
  class Config {
    public:
      /** @brief Constructor **/
      Config() = default;

      /** @brief Destructor **/
      virtual ~Config() = default;

      /** @brief Load from YAML file
       ** @param fileName Name of input YAML file
       **/
      void LoadYaml(const std::string& fileName);

      /** @brief String output (YAML format) **/
      std::string ToString()
      {
        std::stringstream out;
	out << ToYaml();
	return out.str();
      }

      /** @brief Save to YAML file
       ** @param fileName Name of output YAML file
       **/
      void SaveYaml(const std::string& fileName)
      {
        std::ofstream fout(fileName);
	fout << ToYaml();
      }


    private:
      // define here some specific types

      /** @brief Save to YAML node **/
      YAML::Node ToYaml();


    public:
      // Global settings


      // QA settings
      

      // Enabled QA Tasks:
      bool f_task_default = true;

  };

}  // namespace AnalysisTree::QA

#endif /* ANALYSISTREEQA_STEER_CONFIG_H */
