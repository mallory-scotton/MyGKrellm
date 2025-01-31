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
#include "TextMonitor.hpp"
#include <iostream>

///////////////////////////////////////////////////////////////////////////////
TextMonitor::TextMonitor(void) : IMonitorDisplay()
{}

///////////////////////////////////////////////////////////////////////////////
TextMonitor::~TextMonitor()
{}

///////////////////////////////////////////////////////////////////////////////
bool TextMonitor::getInput(void)
{
    char c = getch();

    if (c == 'u') m_user.setEnabled(!m_user.isEnabled());
    if (c == 'm') m_memory.setEnabled(!m_memory.isEnabled());
    if (c == 'o') m_os.setEnabled(!m_os.isEnabled());
    if (c == 'p') m_cpu.setEnabled(!m_cpu.isEnabled());
    if (c == 'n') m_network.setEnabled(!m_network.isEnabled());
    if (c == 't') m_time.setEnabled(!m_time.isEnabled());
    if (c == 'q') return (false);

    return (true);
}

///////////////////////////////////////////////////////////////////////////////
void TextMonitor::printUserModule(void) const
{
    WINDOW *Cwindow = subwin(stdscr, 7, 50, 1, 4);

    if (m_user.isEnabled()) {
        box(Cwindow, ACS_VLINE, ACS_HLINE);
        wattron(Cwindow, A_BOLD);
        mvwprintw(Cwindow, 0, 2, " User ");
        mvwprintw(Cwindow, 2, 14," %s", m_user.getUserName().c_str());
        mvwprintw(Cwindow, 4, 14," %s", m_user.getHostName().c_str());
        wattroff(Cwindow, A_BOLD);
        wrefresh(Cwindow);
    } else {
        wbkgd(Cwindow, COLOR_PAIR(2));
        wrefresh(Cwindow);
    }
}

void TextMonitor::printDateModule(void) const
{
    WINDOW *Cwindow = subwin(stdscr, 5, 50, 8, 4);

    start_color();
    if (m_time.isEnabled()) {
        box(Cwindow, ACS_VLINE, ACS_HLINE);
        mvwprintw(Cwindow, 0, 2, " Time ");
        mvwprintw(Cwindow, 2, 12," %s", m_time.getTime().c_str());
        wrefresh(Cwindow);
    } else {
        wbkgd(Cwindow, COLOR_PAIR(2));
        wrefresh(Cwindow);
    }
}

void TextMonitor::printOsModule(void) const
{
    WINDOW *Cwindow = subwin(stdscr, 7, 50, 13, 4);

    start_color();
    if (m_os.isEnabled()) {
        box(Cwindow, ACS_VLINE, ACS_HLINE);
        mvwprintw(Cwindow, 0, 2, " Operating System ");
        mvwprintw(Cwindow, 2, 18," %s", m_os.getOs().c_str());
        mvwprintw(Cwindow, 4, 13," %s",  m_os.getKernel().c_str());
        wrefresh(Cwindow);
    }  else {
        wbkgd(Cwindow, COLOR_PAIR(2));
        wrefresh(Cwindow);
    }
}

void TextMonitor::printNetworkModule(void) const
{
    WINDOW *Cwindow = subwin(stdscr, 7, 50, 47, 4);

    if (m_network.isEnabled()) {
        int up = m_network.getUp() / 1048576;
        box(Cwindow, ACS_VLINE, ACS_HLINE);
        mvwprintw(Cwindow, 0, 2, " Network ");
        start_color();
        mvwprintw(Cwindow, 2, 4,"UPLOAD: %d MB/s", up);
        up = m_network.getDown() / 1048576;
        mvwprintw(Cwindow, 4, 4,"DOWNLOAD: %d MB/s", up);
        wrefresh(Cwindow);
    } else {
        wbkgd(Cwindow, COLOR_PAIR(2));
        wrefresh(Cwindow);
    }
}

void TextMonitor::printHelp(void) const
{
    WINDOW *Cwindow = subwin(stdscr, 15, 30, 15, 60);

    start_color();
    box(Cwindow, ACS_VLINE, ACS_HLINE);
    mvwprintw(Cwindow, 0, 2, " Help ");
    mvwprintw(Cwindow, 2, 4, "%s", "Hide User data:\t'u'");
    mvwprintw(Cwindow, 4, 4, "%s", "Hide Time:\t\t't'");
    mvwprintw(Cwindow, 6, 4, "%s", "Hide Os data:\t'o'");
    mvwprintw(Cwindow, 8, 4, "%s", "Hide Cpu data:\t'p'");
    mvwprintw(Cwindow, 10, 4, "%s", "Hide Memory data:\t'm'");
    mvwprintw(Cwindow, 12, 4, "%s", "Hide Network data:\t'n'");
    wrefresh(Cwindow);
}

///////////////////////////////////////////////////////////////////////////////
int TextMonitor::loop(void)
{
    initscr();
    noecho();
    cbreak();
    timeout(400);
    curs_set(0);
    start_color();
    keypad(stdscr, 1);
    use_default_colors();
    init_pair(10, COLOR_RED, -1);
    init_pair(11, COLOR_GREEN, -1);
    while (getInput()) {
        refresh();
        printUserModule();
        printDateModule();
        printOsModule();
        printNetworkModule();
        printHelp();
    }
    curs_set(1);
    nocbreak();
    endwin();
    return (0);
}
