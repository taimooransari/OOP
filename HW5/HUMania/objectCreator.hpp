#include "pigeon.hpp"
#include "bee.hpp"
#include "butterfly.hpp"
#include "unit.hpp"
// Class ObjectCreator which is used to randomly return a Unit object.
class ObjectCreator
{
public:
    Unit *getObject(int, int);
};