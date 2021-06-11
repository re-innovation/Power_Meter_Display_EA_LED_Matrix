#include <MutilaDebug.h>
#include "SetMaxPowerMode.h"
#include "PowerMode.h"
#include "Settings.h"
#include "Matrix.h"

SetMaxPowerMode_ SetMaxPowerMode;

void SetMaxPowerMode_::start(const char* data)
{
    DB(F("SetMaxPowerMode::start "));
    DBLN(data);
    Matrix.clear();
    Matrix.setFont(2);
    String s = data;
    uint16_t old = MaxPowerWatts.get();
    bool ok = MaxPowerWatts.set(s.toInt());
    //Matrix.clear();
    Matrix.text(MATRIX_ORANGE, 2, 2, "Max Power");
    if (ok) {
        MaxPowerWatts.save();
        Matrix.text(MATRIX_ORANGE, 2, 12, s);
        Matrix.text(MATRIX_ORANGE, 32, 12, "W");
        PowerMode.reset();
    } else {
        Matrix.text(MATRIX_ORANGE, 2, 12, "Error");
        MaxPowerWatts.set(old);
    }
    Matrix.paint();
    // Then want to return to the previous mode?
    
}
