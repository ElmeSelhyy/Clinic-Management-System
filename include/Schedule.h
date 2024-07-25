#include <Slot.h>
#include <vector>

class Schedule
{
private:
    std::vector<Slot> slots;

public:
    Slot getavailableSlots();
    void addSlot(Slot &slot);
    void removeSlot(Slot &slot);
    void getSlots();
};
