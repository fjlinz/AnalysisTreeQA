/* Copyright (c) 2023 GSI Helmholtzzemtrum fuer Schwerionenforschung, Darmstadt
 * SPDX-License-Identifier: GPL-3.0-only
 * Authors: Frederic Linz [committer] */

/** @file Application.hpp
 ** @author Frederic Linz <f.linz@gsi.de>
 ** @date 18.07.2023
 **/

#ifndef ANALYSISTREEQA_APP_APPLICATION_H
#define ANALYSISTREEQA_APP_APPLICATION 1

#include "ProgramOptions.hpp"
#include "Run.hpp"

namespace AnalysisTree::QA
{
  
  class Application {
    

    public:
      /** @brief standard constructor to initialize the application
       ** @param opt  **/
      explicit Application(ProgramOptions const& opt);

      /** @brief Copy constructor forbidden **/
      Application(const Application&) = delete;

      /** @brief Assignment operator forbidden **/
      void operator=(const Application&) = delete;

      /** @brief Destructor **/
      ~Application() = default;

      /** @brief Run the application **/
      void Exec();

    private:
      const std::string& OutputFile() const;
      const std::string& ConfigFile() const;


    private:
      ProgramOptions const& fOpt;  ///< Program options object
      Run fRun = {};               ///< QA run
  };

}  // namespace AnalysisTree::QA

#endif /* ANALYSISTREEQA_APP_APPLICATION */
