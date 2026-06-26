#include "Map.h"
#include "Cartographer.h"
std::shared_ptr<Map> Map::unlink()
{
    auto m = std::make_shared<Map>();
    m->t = t->clone();
    for (auto& i : this->workers) {
        m->workers.push_back(i);
    }
    return m;
}

void Map::addCartographer(std::shared_ptr<Cartographer> c)
{
    for (auto& i : workers) {
        if (i->getName() == c->getName()) {
            throw MyException("CannotAddCartographer");
        }
    }
    workers.push_back(c);
}

void Map::execute(std::unique_ptr<Command> c)
{
    c->execute(*t);
    history.push_back(std::move(c));
}

void Map::undo()
{
    auto& command = history.back();
    command->unexecute(*t);
    history.pop_back();

}

void Map::printHistory() const
{
    for (auto& i : history) {
        i->description(*t);
    }
}

std::shared_ptr<Territory>& Map::getTerritory()
{
    return t;
}

bool Map::isLinked()
{
    if (t.use_count() > 1) {
        return 1;
    }
    return 0;
}

int Map::useCount()
{
    return t.use_count();
}
