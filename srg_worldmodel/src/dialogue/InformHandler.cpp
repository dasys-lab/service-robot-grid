#include "srg/dialogue/InformHandler.h"

#include "srg/conceptnet/Concept.h"
#include "srg/conceptnet/ConceptNet.h"
#include "srg/dialogue/AnswerGraph.h"

#include "srg/SRGWorldModel.h"

namespace srg
{
namespace dialogue
{

InformHandler::InformHandler(SRGWorldModel* wm) : wm(wm) {
    this->cn = this->wm->conceptNet;
}

AnswerGraph * InformHandler::answerInform(std::string need) {
    srg::dialogue::AnswerGraph* answerGraph = new srg::dialogue::AnswerGraph();
    conceptnet::Concept* root = this->cn->getConcept(answerGraph, need);
    answerGraph->setRoot(root);

    root->addEdges(this->cn->getEdges(answerGraph,root->term, -1));

    this->cn->findInconsistencies(answerGraph);
    answerGraph->renderDot(true);
    return answerGraph;
}
} // namespace dialogue
} // namespace srg