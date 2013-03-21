/*
** DLHandler.h for src in /Users/sabs231/Documents/EPITECH/Classes/C++/Projects/Nibbler/nibbler/src
**
** Made by sergioandres baezserrano
** Login   <baezse_s@epitech.net>
**
** Started on  Thu Mar 21 21:32:15 2013 sergioandres baezserrano
** Last update Thu Mar 21 21:34:18 2013 sergioandres baezserrano
*/

#ifndef DLHANDLER_HH_
#  define DLHANDLER_HH_

#  include  <string>
#  include  <map>
#  include  "DLSymbol.hh"

class DLSymbol;

class DLHandler
{
  protected:
    std::map<std::string, DLSymbol *>   symbols;

  public:
    DLHandler();
    virtual ~DLHandler();
};

#endif /* !DLHANDLER_HH_ */
