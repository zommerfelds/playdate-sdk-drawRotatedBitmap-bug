#include <stdio.h>
#include <stdlib.h>

#include "pd_api.h"

static int update(void *userdata) { return 1; }

#ifdef _WINDLL
__declspec(dllexport)
#endif
int
eventHandler(PlaydateAPI *pd, PDSystemEvent event, uint32_t arg)
{
	if (event == kEventInit)
	{
		LCDBitmap *bitmap = pd->graphics->loadBitmap("rect.png", NULL);

		for (int i = 0; i < 12; i++)
		{
			pd->graphics->drawRotatedBitmap(
				bitmap, 100, 100, i / 12.0f * 360.0f, 0.0f, 0.0f, 1.0f, 1.0f);
		}

		pd->system->setUpdateCallback(update, pd);
	}

	return 0;
}
