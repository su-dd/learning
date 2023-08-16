#ifndef FLYWEIGHTFACTORY_H
#define FLYWEIGHTFACTORY_H
#include "IceCream_halfFareImpl.h"
#include "Chips_freeImpl.h"
#include <map>
class FlyweightFactory
{
public:
    enum StrategyType
    {
        IceCream_halfFare,
        Chips_free
    };
public:
    ~FlyweightFactory()
    {
        for (auto item : m_oStrategyMap)
        {            
            delete item.second;
            item.second = nullptr;
        }
        m_oStrategyMap.clear();

    }

    SaleStrategyInterface* getStrategy(StrategyType type)
    {
        auto item = m_oStrategyMap.find(type);
        if (item == m_oStrategyMap.end())
        {
            switch (type)
            {
            case IceCream_halfFare:
                m_oStrategyMap.insert(std::pair<int, SaleStrategyInterface*>(type, new IceCream_halfFareImpl()));
                item = m_oStrategyMap.find(type);
                break;
            case Chips_free:
                m_oStrategyMap.insert(std::pair<int, SaleStrategyInterface*>(type, new Chips_freeImpl()));
                item = m_oStrategyMap.find(type);
                break;
            default:
                break;
            }
        }
        return item->second;
    }

private:
    std::map<int, SaleStrategyInterface*> m_oStrategyMap;
};
#endif // FLYWEIGHTFACTORY_H
