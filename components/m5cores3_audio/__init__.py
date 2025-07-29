import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.components import audio
from esphome.const import CONF_ID, CONF_MAX_CHANNELS

CODEOWNERS = ["@RikerZhu"]
DEPENDENCIES = ["audio"]

m5cores3_audio_ns = cg.esphome_ns.namespace("m5cores3_audio")
M5CoreS3Audio = m5cores3_audio_ns.class_("M5CoreS3Audio", cg.Component, audio.AudioBackend)

CONFIG_SCHEMA = audio.AUDIO_BACKEND_SCHEMA.extend({
    cv.GenerateID(): cv.declare_id(M5CoreS3Audio),
    cv.Required(1): cv.int_range(min=1, max=2),
})

async def to_code(config):
    var = cg.new_Pvariable(config[CONF_ID])
    await cg.register_component(var, config)
    await audio.register_audio_backend(var, config)
