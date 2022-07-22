#include "theme_ui_manager.h"
#include "event_data.h"

static const u16 ModernUI_Bag[2048] = {
    0x07, 0x407,  0x1D,  0x03,  0x03,  0x03,  0x03,  0x03,  0x03,  0x03,  0x03,  0x03, 0x41D,  0x04,  0x05,  0x05,  0x05,  0x05,  0x05,  0x05,  0x05,  0x05,  0x05,  0x05,  0x05,  0x05,  0x05,  0x05,  0x05,  0x06,  0x11,  0x11,
    0x1E, 0x41E, 0x81D, 0x803, 0x803, 0x803, 0x803, 0x803, 0x803, 0x803, 0x803, 0x803, 0xC1D,  0x09,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x0A,  0x11,  0x11,
    0x02,  0x02,  0x02,  0x02,  0x02,  0x02,  0x02,  0x02,  0x02,  0x02,  0x02,  0x02,  0x02,  0x09,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x0A,  0x11,  0x11,
    0x02,  0x02,  0x02,  0x02,  0x02,  0x02,  0x02,  0x02,  0x02,  0x02,  0x02,  0x02,  0x02,  0x09,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x0A,  0x11,  0x11,
    0x02,  0x02,  0x02,  0x02,  0x02,  0x02,  0x02,  0x02,  0x02,  0x02,  0x02,  0x02,  0x02,  0x09,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x0A,  0x02,  0x02,
    0x02,  0x02,  0x02,  0x02,  0x02,  0x02,  0x02,  0x02,  0x02,  0x02,  0x02,  0x02,  0x02,  0x09,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x0A,  0x02,  0x02,
    0x02,  0x02,  0x02,  0x02,  0x02,  0x02,  0x02,  0x02,  0x02,  0x02,  0x02,  0x02,  0x02,  0x09,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x0A,  0x02,  0x02,
    0x02,  0x02,  0x02,  0x02,  0x02,  0x02,  0x02,  0x02,  0x02,  0x02,  0x02,  0x02,  0x02,  0x09,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x0A,  0x02,  0x02,
    0x0C,  0x0D,  0x0D,  0x0D, 0x40C,  0x02,  0x02,  0x02,  0x02,  0x02,  0x02,  0x02,  0x02,  0x09,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x0A,  0x02,  0x02,
    0x0E,  0x11,  0x11,  0x11, 0x40E,  0x02,  0x02,  0x02,  0x02,  0x02,  0x02,  0x02,  0x02,  0x09,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x0A,  0x02,  0x02,
    0x0E,  0x11,  0x11,  0x11, 0x40E,  0x02,  0x02,  0x02,  0x02,  0x02,  0x02,  0x02,  0x02,  0x09,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x0A,  0x02,  0x02,
    0x0E,  0x11,  0x11,  0x11, 0x40E,  0x02,  0x02,  0x02,  0x02,  0x02,  0x02,  0x02,  0x02,  0x09,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x0A,  0x02,  0x02,
    0x01,  0x12,  0x12,  0x12,  0x13,  0x14,  0x14,  0x14,  0x14,  0x14,  0x14,  0x14,  0x15,  0x16,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x0A,  0x02,  0x02,
    0x17,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x18,  0x19,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x0A,  0x02,  0x02,
    0x17,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x18,  0x19,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x0A,  0x02,  0x02,
    0x17,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x18,  0x19,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x0A,  0x02,  0x02,
    0x17,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x18,  0x19,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x0A,  0x02,  0x02,
    0x17,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x18,  0x19,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x0A,  0x02,  0x02,
    0x17,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x18,  0x19,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x0A,  0x02,  0x02,
    0x1A, 0x80D, 0x80D, 0x80D, 0x80D, 0x80D, 0x80D, 0x80D, 0x80D, 0x80D, 0x80D, 0x80D,  0x1B,  0x1C, 0x805, 0x805, 0x805, 0x805, 0x805, 0x805, 0x805, 0x805, 0x805, 0x805, 0x805, 0x805, 0x805, 0x805, 0x805, 0x806,  0x02,  0x11
};

static const u16 ClassicUI_Bag[2048] = {
    0x05,  0x06,  0x07,  0x08,  0x08,  0x08,  0x08,  0x08,  0x08,  0x08,  0x08,  0x08,  0x09,  0x2F,  0x2E,  0x2E,  0x2E,  0x2E,  0x2E,  0x2E,  0x2E,  0x2E,  0x2E,  0x2E,  0x2E,  0x2E,  0x2E,  0x2E,  0x2E, 0x42F,  0x00,  0x00,
    0x0C,  0x0D,  0x0E, 0x808, 0x808, 0x808, 0x808, 0x808, 0x808, 0x808, 0x808, 0x808,  0x0F,  0x2D,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11, 0x401,  0x00,  0x00,
    0x02,  0x02,  0x02,  0x02,  0x39,  0x3A,  0x3B,  0x3C,  0x3D,  0x3E,  0x3F,  0x02,  0x02,  0x01,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11, 0x401,  0x00,  0x00,
    0x02,  0x02,  0x02,  0x02,  0x02,  0x02,  0x02,  0x02,  0x02,  0x02,  0x02,  0x02,  0x02,  0x01,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11, 0x401,  0x00,  0x00,
    0x02,  0x02,  0x02,  0x02,  0x02,  0x02,  0x02,  0x02,  0x02,  0x02,  0x02,  0x02,  0x02,  0x01,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11, 0x401,  0x00,  0x00,
    0x02,  0x02,  0x02,  0x02,  0x02,  0x02,  0x02,  0x02,  0x02,  0x02,  0x02,  0x02,  0x02,  0x01,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11, 0x401,  0x00,  0x00,
    0x02,  0x02,  0x02,  0x02,  0x02,  0x02,  0x02,  0x02,  0x02,  0x02,  0x02,  0x02,  0x02,  0x01,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11, 0x401,  0x00,  0x00,
    0x02,  0x02,  0x02,  0x02,  0x02,  0x02,  0x02,  0x02,  0x02,  0x02,  0x02,  0x02,  0x02,  0x01,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11, 0x401,  0x00,  0x00,
    0x02,  0x02,  0x02,  0x02,  0x02,  0x02,  0x02,  0x02,  0x02,  0x02,  0x02,  0x02,  0x02,  0x01,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11, 0x401,  0x00,  0x00,
    0x02,  0x02,  0x02,  0x02,  0x02,  0x02,  0x02,  0x02,  0x02,  0x02,  0x02,  0x02,  0x02,  0x01,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11, 0x401,  0x00,  0x00,
    0x37,  0x24,  0x24, 0x437,  0x02,  0x02,  0x02,  0x02,  0x02,  0x02,  0x02,  0x02,  0x02,  0x01,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11, 0x401,  0x00,  0x00,
    0x27,  0x16,  0x16, 0x427,  0x02,  0x02,  0x02,  0x02,  0x02,  0x02,  0x02,  0x02,  0x02,  0x01,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11, 0x401,  0x00,  0x00,
    0x27,  0x16,  0x16, 0x427,  0x02,  0x02,  0x02,  0x02,  0x02,  0x02,  0x02,  0x02,  0x02,  0x01,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11, 0x401,  0x00,  0x00,
    0x35,  0x36,  0x36, 0x435,  0x02,  0x02,  0x02,  0x02,  0x02,  0x02,  0x02,  0x02,  0x02,  0x01,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11, 0x401,  0x00,  0x00,
    0x23,  0x2C,  0x2C,  0x2C,  0x2C,  0x2C,  0x2C,  0x2C,  0x2C,  0x2C,  0x2C,  0x2C, 0x423,  0x01,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11, 0x401,  0x00,  0x00,
    0x27,  0x16,  0x16,  0x16,  0x16,  0x16,  0x16,  0x16,  0x16,  0x16,  0x16,  0x16, 0x427,  0x01,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11, 0x401,  0x00,  0x00,
    0x27,  0x16,  0x16,  0x16,  0x16,  0x16,  0x16,  0x16,  0x16,  0x16,  0x16,  0x16, 0x427,  0x01,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11, 0x401,  0x00,  0x00,
    0x27,  0x16,  0x16,  0x16,  0x16,  0x16,  0x16,  0x16,  0x16,  0x16,  0x16,  0x16, 0x427,  0x01,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11, 0x401,  0x00,  0x00,
    0x27,  0x16,  0x16,  0x16,  0x16,  0x16,  0x16,  0x16,  0x16,  0x16,  0x16,  0x16, 0x427,  0x01,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11, 0x401,  0x00,  0x00,
    0x823, 0x82C, 0x82C, 0x82C, 0x82C, 0x82C, 0x82C, 0x82C, 0x82C, 0x82C, 0x82C, 0x82C, 0xC23, 0x82F, 0x82E, 0x82E, 0x82E, 0x82E, 0x82E, 0x82E, 0x82E, 0x82E, 0x82E, 0x82E, 0x82E, 0x82E, 0x82E, 0x82E, 0x82E, 0xC2F,  0x00,  0x00
};


static const u16* UITemplates[1][THEME_UI_MAX-1] = {
    {ModernUI_Bag, ClassicUI_Bag}
};

const u16* GetUITemplate(u16 templateId) {
    //memset(TemplateContainer, 0, sizeof(u16)*2048);
    //CpuCopy16(UITemplates[templateId][VarGet(VAR_HAT_THEME_UI_NUMBER)], (u16*)TemplateContainer, 2048);
    //memcpy((u16*)TemplateContainer, UITemplates[templateId][VarGet(VAR_HAT_THEME_UI_NUMBER)], 2048*2);
    return UITemplates[templateId][VarGet(VAR_HAT_THEME_UI_NUMBER)];
}