/* Copyright (c) 2023 GSI Helmholtzzentrum fuer Schwerionenforschung, Darmstadt
 * SPDX-License-Identifier: GPL-3.0-only
 * Authors: Frederic Linz [committer] */

/** @file ProgramOptions.hpp
 ** @author Frederic Linz <f.linz@gsi.de>
 ** @date 18.07.2023 
 **/

#ifndef ANALYSISTREEQA_APP_PROGRAMOPTIONS_H
#define ANALYSISTREEQA_APP_PROGRAMOPTIONS_H 1

#define DEFAULT_CONFIG "config.yaml"  // Define here the path to the default config.yaml

#include <string>

namespace AnalysisTree::QA
{

  /** @class ProgramOptions
   ** @author Frederic Linz <f.linz@gsi.de>
   ** @since 18 July 2023
   **
   ** Program option class for the application AnalysisTreeQA
   **/
  class ProgramOptions {
    public:
      /** @brief Standard constructor with command line arguments **/
      ProgramOptions(int argc, char* argv[]) { ParseOptions(argc, argv); }

      /** @brief Copy constructor forbidden **/
      ProgramOptions(const ProgramOptions&) = delete;

      /** @brief Assignment operator forbidden **/
      ProgramOptions& operator=(const ProgramOptions&) = delete;

      /** @brief Destructor **/
      ~ProgramOptions() = default;

      /** @brief Get input file name **/
      [[nodiscard]] const std::string& InputFile() const { return fInput; }

      /** @brief Get output file name **/
      [[nodiscard]] const std::string& OutputFile() const { return fOutput; }

      /** @brief Get configuration file name (YAML format) **/
      [[nodiscard]] const std::string& ConfigFile() const { return fConfig; }

      /** @brief Get overwrite option **/
      [[nodiscard]] bool Overwrite() const { return fOverwrite; } 


    private:
      /** @brief Parse command line arguments using boost program_options **/
      void ParseOptions(int argc, char* argv[]);


    private:			   /// members
      std::string fInput  = "";    ///< Input filelist (TXT format, one ROOT file/line)
      std::string fOutput = "";    ///< Output fine name (ROOT format)
      std::string fConfig = "";    ///< Configuration file name (YAML format)
      bool fOverwrite     = false; ///< Enable overwriting of existing output file
  };

}  // namespace AnalysisTree::QA

#endif /* ANALYSISTREEQA_APP_PROGRAMOPTIONS_H */
