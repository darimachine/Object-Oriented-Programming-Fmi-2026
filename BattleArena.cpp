#include "BattleArena.h"

BattleArena::BattleArena(Character* first, Character* second)
{
	characters[0] = first;
	characters[1] = second;
}

void BattleArena::tickEffects()
{
    for (int i = 0; i < MAX_LEN_CHARACTERS; i++)
    {
        auto& effects = characters[i]->getEffects();

        for (auto it = effects.begin(); it != effects.end();)
        {
            (*it)->tick(*characters[i]);

            if ((*it)->isExpired())
            {
                it = effects.erase(it);
            }
            else
            {
                ++it;
            }
        }
    }
}

void BattleArena::runRound()
{
    tickEffects();

    try
    {
        if (!characters[0]->isDead() && !characters[0]->isStunned())
        {
            characters[0]->attack(*characters[1]);
        }
        else if (characters[0]->isStunned())
        {
            characters[0]->setStunned(false);
        }
    }
    catch (const OutOfManaException& e)
    {
        std::cout << e.what() << '\n';
        characters[0]->rest();
    }
    catch (const DeadCharacterException& e)
    {
        std::cout << e.what() << '\n';
        return;
    }

    try
    {
        if (!characters[1]->isDead() && !characters[1]->isStunned())
        {
            characters[1]->attack(*characters[0]);
        }
        else if (characters[1]->isStunned())
        {
            characters[1]->setStunned(false);
        }
    }
    catch (const OutOfManaException& e)
    {
        std::cout << e.what() << '\n';
        characters[1]->rest();
    }
    catch (const DeadCharacterException& e)
    {
        std::cout << e.what() << '\n';
        return;
    }

    std::cout << characters[0]->statusLine() << '\n';
    std::cout << characters[1]->statusLine() << '\n';
}

bool BattleArena::isOver()const
{
    return characters[0]->isDead() || characters[1]->isDead();
}

void BattleArena::addEffect(int characterIndex, std::unique_ptr<StatusEffect> effect)
{
    characters[characterIndex]->getEffects().push_back(std::move(effect));
}
