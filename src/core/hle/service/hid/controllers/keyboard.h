// SPDX-FileCopyrightText: Copyright 2018 yuzu Emulator Project
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#include "core/hle/service/hid/controllers/controller_base.h"
#include "core/hle/service/hid/controllers/types/keyboard_types.h"

namespace Service::HID {
class Keyboard final : public ControllerBase {
public:
    explicit Keyboard(Core::HID::HIDCore& hid_core_);
    ~Keyboard() override;

    // Called when the controller is initialized
    void OnInit() override;

    // When the controller is released
    void OnRelease() override;

    // When the controller is requesting an update for the shared memory
    void OnUpdate(const Core::Timing::CoreTiming& core_timing) override;

private:
    KeyboardState next_state{};
    Core::HID::EmulatedDevices* emulated_devices = nullptr;
};
} // namespace Service::HID
