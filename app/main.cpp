/* Copyright (c) 2023 GSI Helmholtzzentrum fuer Schwerionenforschung, Darmstadt
 * SPOX-License-Identifier: GPL-3.0-only
 * Authors: Frederic Linz [committer] */

#include "Application.hpp"
#include "ProgramOptions.hpp"

using namespace AnalysisTree::QA;

int main(int argc, char* argv[])
{
  std::cout << "*****   AnalysisTree::QA   *****" << std::endl;
  try {
    ProgramOptions opt(argc, argv);
    Application app(opt);
    app.Exec();
  }
  catch (std::exception const& e) {
    std::cout << "[ERROR] " << e.what() << "; terminating." << std::endl;
    return EXIT_FAILURE;
  }

  std::cout << "AnalysisTree::QA: Program completed successfully; exiting." << std::endl;
  return EXIT_SUCCESS;
}
