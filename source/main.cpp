///////////////////////////////////////////////////////////////////////////////
///
/// MIT License
///
/// Copyright(c) 2025 TekyoDrift
///
/// Permission is hereby granted, free of charge, to any person obtaining a
/// copy of this software and associated documentation files (the "Software"),
/// to deal in the Software without restriction, including without limitation
/// the rights to use, copy, modify, merge, publish, distribute, sublicense,
/// and/or sell copies of the Software, and to permit persons to whom the
/// Software is furnished to do so, subject to the following coditions:
///
/// The above copyright notice and this permission notice shall be included
/// in all copies or substantial portions of the Software?
///
/// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
/// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
/// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
/// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
/// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
/// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
/// DEALINGS IN THE SOFTWARE.
///
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
// Dependencies
///////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include "IMonitorModule.hpp"
#include "TextMonitor.hpp"

static int printHelp(int code)
{
    std::cout << "./MyGKrellm [-g/--graphical][-t/--text][-h/--help]" << std::endl;
    std::cout << "\t--graphical :\tDisplay in graphical mode." << std::endl;
    std::cout << "\t--text      :\tDisplay in text mode." << std::endl;
    std::cout << "\t--help      :\tDisplay help." << std::endl;
    return (code);
}

int main(int argc, char *argv[])
{
    std::string arg;

    if (argc != 2)
        return (printHelp(84));
    arg = argv[1];
    if (arg == "--help" || arg == "-h")
        return (printHelp(0));
    if (arg == "--graphical" || arg == "-g")
        return (0);
    if (arg == "--text" || arg == "-t")
        return (TextMonitor().loop());
    return (printHelp(84));
}

// #include "modules/UserModule.hpp"
// #include "modules/TimeModule.hpp"
// #include "modules/OsModule.hpp"
// #include "modules/NetworkModule.hpp"
// #include "modules/CpuModule.hpp"
// #include "modules/MemoryModule.hpp"

// int main(void)
// {
//     UserModule user;
//     TimeModule time;
//     OsModule os;
//     NetworkModule network;
//     CpuModule cpu;
//     MemoryModule memory;

//     user.refresh();
//     std::cout << "USER_MODULE:" << std::endl;
//     std::cout << "\tUserName: " << user.getUserName() << std::endl;
//     std::cout << "\tHostName: " << user.getHostName() << std::endl;

//     time.refresh();
//     std::cout << "TIME_MODULE:" << std::endl;
//     std::cout << "\tCurrentTime: " << time.getTime() << std::endl;

//     os.refresh();
//     std::cout << "OS_MODULE:" << std::endl;
//     std::cout << "\tOs: " << os.getOs() << std::endl;
//     std::cout << "\tKernel: " << os.getKernel() << std::endl;

//     network.refresh();
//     std::cout << "NETWORK_MODULE:" << std::endl;
//     std::cout << "\tDown: " << network.getDown() << std::endl;
//     std::cout << "\tUp: " << network.getUp() << std::endl;

//     cpu.refresh();
//     std::cout << "CPU_MODULE:" << std::endl;

//     std::vector<CpuModule::Proc> info = cpu.getProcs();

//     for (size_t i = 0; i < info.size(); i++) {
//         std::cout << "\tCPU " << i << ": " << std::endl;
//         for (const auto& pair : info[i]) {
//             std::cout << "\t\t" << pair.first << ": " << pair.second << std::endl;
//         }
//     }

//     memory.refresh();
//     std::cout << "MEMORY_MODULE:" << std::endl;
//     std::cout << "\tMemory Total: " << memory.getMemoryTotal() << std::endl;
//     std::cout << "\tMemory Free: " << memory.getMemoryFree() << std::endl;
//     std::cout << "\tMemory Used: " << memory.getMemoryUsed() << std::endl;
//     std::cout << "\tSwap Total: " << memory.getSwapTotal() << std::endl;
//     std::cout << "\tSwap Free: " << memory.getSwapFree() << std::endl;
//     std::cout << "\tSwap Used: " << memory.getSwapUsed() << std::endl;

//     return (0);
// }
