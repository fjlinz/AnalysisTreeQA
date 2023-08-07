/* Copyright (c) 2023 GSI Helmholtzzentrum fuer Schwerionenforschung, Darmstadt
 * SPDX-License-Identifier: GPL-3.0-only
 * Authors: Frederic Linz [committer] */

/** @file TaskFactory.cxx
 ** @author Frederic Linz <f.linz@gsi.de>
 ** @date 18.07.2023
 **/

#include "TaskFactory.hpp"

#include "Task.hpp"

#include <TSystem.h>

namespace AnalysisTree::QA
{

  // ----- Constructor ----------
  TaskFactory::TaskFactory(Run* run) : fRun(run) {}
  // ----------------------------
  
  
  // Define here the tasks which should be registered to fRun via AddTask
//  void TaskFactory::RegisterDefaultHistograms(AnalysisTree::QA::Task& task)
  void TaskFactory::RegisterDefaultHistograms(Task& task)
  {
    assert(fRun);

    // --- Define histograms of the default QA
    task.AddH1({"x_{vertex}^{MC} (cm)", {"SimEventHeader", "vtx_x"}, {200, -1, 1}});

    std::cout << "AnalysisTree::QA::Task: Default registered" << std::endl;
  }


}  // namespace AnalysisTree::QA
