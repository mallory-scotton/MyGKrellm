/*
** EPITECH PROJECT, 2025
** MyGKrellm
** File description:
** IMonitorDisplay
*/

#include "IMonitorDisplay.hpp"

void IMonitorDisplay::refresh(void)
{
    m_cpu.refresh();
    m_memory.refresh();
    m_network.refresh();
    m_os.refresh();
    m_time.refresh();
    m_user.refresh();
}
