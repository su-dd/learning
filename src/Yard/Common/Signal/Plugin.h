#ifndef PLUGIN_H
#define PLUGIN_H
#include "Signal.h"
#include <mutex>
#include <map>
#include <string>

namespace CommonPlugin {

static void registerPlugin()
{

}

static void freePlugin()
{

}

class Plugin
{
public:
    static Plugin *getInstance()
    {
        return &m_pInstance;
    }
private:
    static Plugin m_pInstance;
//    std::map<std::string, CommonSignal::Slot()>
};
// 初始化静态变量
Plugin Plugin::m_pInstance;
}

#endif // PLUGIN_H
