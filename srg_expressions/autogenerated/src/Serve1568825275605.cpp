#include "Serve1568825275605.h"
/*PROTECTED REGION ID(eph1568825275605) ENABLED START*/
#include <srg/tasks/CommandHandler.h>
/*PROTECTED REGION END*/

namespace alica
{
// Plan:Serve
/**
 * Task: Serve  -> EntryPoint-ID: 1568825285315
 */
std::shared_ptr<UtilityFunction> UtilityFunction1568825275605::getUtilityFunction(Plan* plan)
{
    /*PROTECTED REGION ID(1568825275605) ENABLED START*/
    std::shared_ptr<UtilityFunction> defaultFunction = std::make_shared<DefaultUtilityFunction>(plan);
    return defaultFunction;
    /*PROTECTED REGION END*/
}
/**
 * Outgoing transition:
 *   - Name: 1568825457853, ConditionString: MovingTask received!, Comment: MISSING_COMMENT
 *
 * Abstract plans in current state:
 *   - Stop (1555602210283)
 *
 * Tasks in plan:
 *   - Serve (1555601344076) (Entrypoint: 1568825285315)
 *
 * States in plan:
 *   - WaitForTask (1568825288640)
 *   - MoveToPosition (1568825309813)
 *   - ManipulateObject (1571661663929)
 *   - TransportToPosition (1573418710533)
 *
 * Variables of preconditon:
 */
bool PreCondition1568825457853::evaluate(std::shared_ptr<RunningPlan> rp)
{
    /*PROTECTED REGION ID(1568825336792) ENABLED START*/
    auto taskSequence = this->wm->dialogueManager.commandHandler->getActiveTaskSequence();
    if (!taskSequence) {
        return false;
    }
    auto firstTask = taskSequence->getTask(0);
    return firstTask && firstTask->type == srg::tasks::TaskType::Move && !firstTask->checkAndUpdateSuccess(this->wm);
    /*PROTECTED REGION END*/
}
/**
 * Outgoing transition:
 *   - Name: 1571661980674, ConditionString: Manipulate command!, Comment: MISSING_COMMENT
 *
 * Abstract plans in current state:
 *   - Stop (1555602210283)
 *
 * Tasks in plan:
 *   - Serve (1555601344076) (Entrypoint: 1568825285315)
 *
 * States in plan:
 *   - WaitForTask (1568825288640)
 *   - MoveToPosition (1568825309813)
 *   - ManipulateObject (1571661663929)
 *   - TransportToPosition (1573418710533)
 *
 * Variables of preconditon:
 */
bool PreCondition1571661980674::evaluate(std::shared_ptr<RunningPlan> rp)
{
    /*PROTECTED REGION ID(1571661739802) ENABLED START*/
    auto taskSequence = this->wm->dialogueManager.commandHandler->getActiveTaskSequence();
    if (!taskSequence) {
        return false;
    }
    auto firstTask = taskSequence->getTask(0);
    return firstTask &&
           (firstTask->type == srg::tasks::TaskType::Open || firstTask->type == srg::tasks::TaskType::Close ||
                   firstTask->type == srg::tasks::TaskType::PutDown || firstTask->type == srg::tasks::TaskType::PickUp) &&
           !firstTask->checkAndUpdateSuccess(this->wm);
    /*PROTECTED REGION END*/
}
/**
 * Outgoing transition:
 *   - Name: 1573418732991, ConditionString: Received a transport task!, Comment: MISSING_COMMENT
 *
 * Abstract plans in current state:
 *   - Stop (1555602210283)
 *
 * Tasks in plan:
 *   - Serve (1555601344076) (Entrypoint: 1568825285315)
 *
 * States in plan:
 *   - WaitForTask (1568825288640)
 *   - MoveToPosition (1568825309813)
 *   - ManipulateObject (1571661663929)
 *   - TransportToPosition (1573418710533)
 *
 * Variables of preconditon:
 */
bool PreCondition1573418732991::evaluate(std::shared_ptr<RunningPlan> rp)
{
    /*PROTECTED REGION ID(1573418725423) ENABLED START*/
    auto taskSequence = this->wm->dialogueManager.commandHandler->getActiveTaskSequence();
    if (!taskSequence) {
        return false;
    }
    auto firstTask = taskSequence->getTask(0);
    return firstTask && firstTask->type == srg::tasks::TaskType::Search && !taskSequence->checkAndUpdateSuccess(this->wm);
    /*PROTECTED REGION END*/
}
/**
 * Outgoing transition:
 *   - Name: 1568825476581, ConditionString: Movement successful!, Comment: MISSING_COMMENT
 *
 * Abstract plans in current state:
 *   - Move (1568825137528)
 *
 * Tasks in plan:
 *   - Serve (1555601344076) (Entrypoint: 1568825285315)
 *
 * States in plan:
 *   - WaitForTask (1568825288640)
 *   - MoveToPosition (1568825309813)
 *   - ManipulateObject (1571661663929)
 *   - TransportToPosition (1573418710533)
 *
 * Variables of preconditon:
 */
bool PreCondition1568825476581::evaluate(std::shared_ptr<RunningPlan> rp)
{
    /*PROTECTED REGION ID(1568825392354) ENABLED START*/
    return rp->isAnyChildStatus(PlanStatus::Success);
    /*PROTECTED REGION END*/
}
/**
 * Outgoing transition:
 *   - Name: 1571661864299, ConditionString: Manipulation successful!, Comment: MISSING_COMMENT
 *
 * Abstract plans in current state:
 *   - Manipulate (1571687572903)
 *
 * Tasks in plan:
 *   - Serve (1555601344076) (Entrypoint: 1568825285315)
 *
 * States in plan:
 *   - WaitForTask (1568825288640)
 *   - MoveToPosition (1568825309813)
 *   - ManipulateObject (1571661663929)
 *   - TransportToPosition (1573418710533)
 *
 * Variables of preconditon:
 */
bool PreCondition1571661864299::evaluate(std::shared_ptr<RunningPlan> rp)
{
    /*PROTECTED REGION ID(1571661809581) ENABLED START*/
    return rp->isAnyChildStatus(PlanStatus::Success);
    /*PROTECTED REGION END*/
}
/**
 * Outgoing transition:
 *   - Name: 1573418838905, ConditionString: I am in the Pseudo Success State, Comment: MISSING_COMMENT
 *
 * Abstract plans in current state:
 *   - Transport (1573418869596)
 *
 * Tasks in plan:
 *   - Serve (1555601344076) (Entrypoint: 1568825285315)
 *
 * States in plan:
 *   - WaitForTask (1568825288640)
 *   - MoveToPosition (1568825309813)
 *   - ManipulateObject (1571661663929)
 *   - TransportToPosition (1573418710533)
 *
 * Variables of preconditon:
 */
bool PreCondition1573418838905::evaluate(std::shared_ptr<RunningPlan> rp)
{
    /*PROTECTED REGION ID(1573418821209) ENABLED START*/
    for (auto& child : rp->getChildren()) {
        if (child->getActiveState()->getId() == 1583008553235) { // ID of Pseudo Success State
            return true;
        }
    }
    return false;
    /*PROTECTED REGION END*/
}
} // namespace alica
