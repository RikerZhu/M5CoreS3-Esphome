#pragma once

// #ifdef USE_ESP32

#include <driver/i2s.h>
#include "esphome/core/component.h"
#include "esphome/core/helpers.h"
#include "esphome/components/audio/audio_backend.h"

namespace esphome {
namespace m5cores3_audio {

class M5CoreS3AudioComponent;

class I2SAudioIn : public Parented<M5CoreS3AudioComponent> {};

class I2SAudioOut : public Parented<M5CoreS3AudioComponent> {};


class M5CoreS3Audio : public esphome::Component, public esphome::audio::AudioBackend {
 public:
  void setup() override;
  void dump_config() override;

  esphome::audio::AudioInput *get_input(uint8_t channel) override {
    return this->input_;
  }

  esphome::audio::AudioOutput *get_output(uint8_t channel) override {
    return this->output_;
  }

 protected:
  esphome::audio::AudioInput *input_{nullptr};
  esphome::audio::AudioOutput *output_{nullptr};
};

}  // namespace i2s_audio
}  // namespace esphome

// #endif  // USE_ESP32
