#include "srg/agent/Path.h"

#include <srg/World.h>
#include <srg/world/Door.h>
#include <srg/world/Object.h>
#include <srg/world/RoomType.h>

#include <iostream>

namespace srg
{
namespace agent
{
Path::Path(srg::world::Coordinate start, srg::world::Coordinate goal, srg::SRGWorldModel* wm)
        : start(start)
        , goal(goal)
        , lastStep(nullptr)
{
    this->costs = 1;
    this->cell = wm->sRGSimData.getWorld()->getCell(start);
}

Path::Path(const srg::agent::Path& path)
        : start(path.start)
        , goal(path.goal)
        , costs(path.costs)
        , cell(path.cell)
        , lastStep(path.lastStep)
{
}

Path::~Path()
{
    delete this->lastStep;
}

srg::world::Direction Path::getDirection()
{
    if (start == goal) {
        return srg::world::Direction::None;
    }
    // find the first cell that is not on the start coordinates
    Path* firstStep = this;
    while (firstStep->lastStep->lastStep != nullptr) {
        firstStep = firstStep->lastStep;
    }
    //    std::cout << "Path::getDirection(): First Step is " << firstStep->getCell()->coordinate << " Start is " << this->start <<std::endl;
    if (this->start.x < firstStep->cell->coordinate.x) {
        return srg::world::Direction::Right;
    } else if (this->start.x > firstStep->cell->coordinate.x) {
        return srg::world::Direction::Left;
    } else if (this->start.y < firstStep->cell->coordinate.y) {
        return srg::world::Direction::Down;
    } else if (this->start.y > firstStep->cell->coordinate.y) {
        return srg::world::Direction::Up;
    } else {
        std::cerr << "Path::getDirection(): Path is longer than 1 step, but stays on the same coordinates!" << std::endl;
        return srg::world::Direction::None;
    }
}

bool Path::isGoalPath()
{
    return this->cell->coordinate == this->goal;
}

int Path::getTotalCosts()
{
    return this->costs + this->getHeuristicCosts();
}

int Path::getHeuristicCosts()
{
    return std::abs<int>(this->goal.x - this->cell->coordinate.x) + std::abs<int>(this->goal.y - this->cell->coordinate.y);
}

std::vector<Path*> Path::expand(std::vector<std::shared_ptr<const world::Cell>>& visited)
{
    std::vector<Path*> newPaths;
    if (checkValidity(visited, cell->down)) {
        newPaths.push_back(this->addStep(cell->down));
    }
    if (checkValidity(visited, cell->left)) {
        newPaths.push_back(this->addStep(cell->left));
    }
    if (checkValidity(visited, cell->right)) {
        newPaths.push_back(this->addStep(cell->right));
    }
    if (checkValidity(visited, cell->up)) {
        newPaths.push_back(this->addStep(cell->up));
    }
    return newPaths;
}

/**
 * Only allows to step on floor cells without closed doors on it.
 * @param visited
 * @param cell
 * @return
 */
bool Path::checkValidity(std::vector<std::shared_ptr<const world::Cell>>& visited, std::shared_ptr<world::Cell> cell)
{
    if (!cell) {
        return false;
    }

    auto entry = std::find(visited.begin(), visited.end(), cell);
    if (entry != visited.end()) {
        return false;
    }

    if (cell->getType() == srg::world::RoomType::Wall) {
        return false;
    }

    for (auto& objectEntry : cell->getObjects()) {
        if (std::shared_ptr<srg::world::Door> door = std::dynamic_pointer_cast<srg::world::Door>(objectEntry.second)) {
            return door->isOpen();
        }
    }

    return true;
}

std::shared_ptr<const world::Cell> Path::getCell()
{
    return this->cell;
}

Path* Path::addStep(std::shared_ptr<const world::Cell> cell)
{
    Path* newPath = new Path(*this);
    newPath->lastStep = this;
    newPath->cell = cell;
    newPath->costs++;
    return newPath;
}
} // namespace agent
} // namespace srg
