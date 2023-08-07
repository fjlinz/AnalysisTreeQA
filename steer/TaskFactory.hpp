/* Copyright (c) 2023 GSI Helmholtzzentrum fuer Schwerionenforschung, Darmstadt
 * SPDX-License-Identifier: GPL-3.0-only
 * Authors: Frederic Linz [committer] */

/** @file TaskFactory.h
 ** @author Frederic Linz <f.linz@gsi.de>
 ** @date 18.07.2023
 **/

#ifndef ANALYSISTREEQA_STEER_TASKFACTORY_H
#define ANALYSISTREEQA_STEER_TASKFACTORY_H 1

#include "Run.hpp"

#include "Task.hpp"

namespace AnalysisTree::QA
{
  
  /** @class TaskFactory
   ** @brief Factory class for the instantiation of AnalysisTreeQA tasks
   ** @author Frederic Linz <f.linz@gsi.de>
   ** @since 18 July 2023
   **/
  class TaskFactory {
    public:
      /** @brief Constructor **/
      TaskFactory(Run* steer = nullptr);

      /** @brief Destructor **/
      virtual ~TaskFactory() {};

      // --- Register tasks
//      void RegisterDefaultHistograms(AnalysisTree::QA::Task& task);
      void RegisterDefaultHistograms(Task& task);

    private:
      Run* fRun = nullptr;
  };

}  // namespace AnalysisTree::QA

#endif /* ANALYSISTREEQA_STEER_TASKFACTORY */
