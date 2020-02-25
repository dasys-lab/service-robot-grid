#pragma once

#include <map>
#include <memory>
#include <vector>
#include <srg/agent/containers/SpeechAct.h>

namespace supplementary
{
template <typename>
class InformationElement;
}

namespace control
{
class SpeechAct;
}

namespace srg
{
namespace tasks
{
class TaskHandler;
}
class SRGWorldModel;
namespace dialogue
{
class AnswerGraph;
class InformHandler;
class TaskHandler;
class QuestionHandler;

//#define inconsistency_eval
class DialogueManager
{
public:
    explicit DialogueManager(SRGWorldModel* wm);
    ~DialogueManager();
    void processSpeechAct(std::shared_ptr<supplementary::InformationElement<agent::SpeechAct>> speechActInfo);
    void tick();

    QuestionHandler* questionHandler;
    InformHandler* informHandler;
    srg::tasks::TaskHandler* taskHandler;

private:
    srg::SRGWorldModel* wm;
    std::unordered_map<essentials::IdentifierConstPtr, std::shared_ptr<agent::SpeechAct>> dialogueMap;
    std::vector<std::shared_ptr<agent::SpeechAct>> pendingSpeechActs;
    void renderDot() const;
};
} // namespace dialogue
} // namespace srg
