/* Copyright (c) 2023 GSI Helmholtzzentrum fuer Schwerionenforschung, Darmstadt
 * SPDX-License-Identifier: GPL-3.0-only
 * Authors: Frederic Linz [committer] */

/** @file ProgramOptions.cxx
 ** @author Frederic Linz <f.linz@gsi.de>
 ** @date 18.07.203
 **/

#include "ProgramOptions.hpp"

#include <boost/program_options.hpp>

#include <iostream>

namespace po = boost::program_options;

using std::string;

namespace AnalysisTree::QA
{

  // -----  Parse command line  ----------
  void ProgramOptions::ParseOptions(int argc, char* argv[])
  {
    
    // --- Define generic options
    po::options_description generic("Generic options");
    auto generic_add = generic.add_options();
    generic_add("help,h", "display this help and exit");

    // --- Define configuration options
//    string defconfig = std::getenv("VMCWORKDIR");
//    defconfig.append("/");
//    defconfig.append(DEFAULT_CONFIG);
    string defconfig = DEFAULT_CONFIG;
    po::options_description config("Configuration");
    auto config_add = config.add_options();
    config_add("input,i", po::value<string>(&fInput)->value_name("<file name>"),
		    "name of the input filelist containing AnalysisTree ROOT files");
    config_add("output,o", po::value<string>(&fOutput)->value_name("<file name>"),
		    "name of the output ROOT file with QA histograms");
    config_add("config,c", po::value<string>(&fConfig)->value_name("<file name>")->default_value(defconfig),
		    "name of a YAML configuration file for the QA");
    config_add("overwrite,w", po::bool_switch(&fOverwrite)->default_value(false),
		    "allow to overwrite an existing output file");

    // --- Allowed options
    po::options_description cmdline_options("Allowed options");
    cmdline_options.add(generic).add(config);

    // --- Parse command line
    po::variables_map vars;
    po::store(po::parse_command_line(argc, argv, cmdline_options), vars);
    po::notify(vars);

    // --- Help: print help information and exit program
    if (vars.count("help") != 0u) {
      std::cout << cmdline_options << std::endl;
      exit(EXIT_SUCCESS);
    }

    // --- Catch mandatory parameters not being specified
    if (vars.count("input") == 0u) { throw std::runtime_error("no input file name specified"); }
    if (vars.count("output") == 0u) { throw std::runtime_error("no output file name specified"); }
  }
  // ---------------

} // namespace AnalysisTree::QA
