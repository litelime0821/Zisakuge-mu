#pragma once

#include "../HuEngine.h"

class BG {
public:

    void Load();
    void Initialize();
    void Update();

private:
    HE::Sprite sprite_;
};