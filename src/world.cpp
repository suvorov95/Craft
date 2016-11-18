#include "config.h"
#include "item.h"

extern "C" {
#include "noise.h"
}
//tet
#include "world.h"
void __declspec(dllexport) create_world(int p, int q, world_func func, void *arg)
{
	int pad = 1;
	for (int dx = -pad; dx < CHUNK_SIZE + pad; dx++) {
		for (int dz = -pad; dz < CHUNK_SIZE + pad; dz++) {
			int flag = 1;
			if (dx < 0 || dz < 0 || dx >= CHUNK_SIZE || dz >= CHUNK_SIZE) {
				flag = -1;
			}
			int x = p * CHUNK_SIZE + dx;
			int z = q * CHUNK_SIZE + dz;
			float f = simplex2(x * 0.001, z * 0.001, 1, 1.5, 2);
			float g = simplex2(-x * 0.003, -z * 0.003, 2, 3.5, 1);
			int mh = g * 64; //âûñîòà ãîð
			int h = f * mh + 56; //îáùàÿ âûñîòà ìèðà
			int w = 1; //áëîê òðàâû

			for (int y = 0; y < h && y < 200; y++) {

				func(x, y, z, GRASS * flag, arg);



				if (y == h - 1)

				{

					func(x, y - 1, z, DIRT * flag, arg);



					for (int j = y - 2; j > 0; j--)

					{

						func(x, j, z, CEMENT * flag, arg);

					}

				}
			}

			for (int y = 40; y < 64; y++) { //íà óðîâíÿõ îò 40 äî 64 - âîäà
				if (h <= 64 && w != 6)
				{
					h = 64;
					func(x, y + 1, z, COLOR_26 * flag, arg);
				} //water
			}

			/*if (w == 1) {
				if (SHOW_PLANTS) {
					// grass
					if (simplex2(-x * 0.1, z * 0.1, 4, 0.8, 2) > 0.6) {
						if (h > 64 && w != 2) func(x, h, z, 17 * flag, arg); // åñëè âûñîòà âûøå óðîâíÿ ìîðÿ è ýòî íå ìîðå - òî òðàâà
					}
					// flowers
					if (simplex2(x * 0.05, -z * 0.05, 4, 0.8, 2) > 0.7) {
						int w = 18 + simplex2(x * 0.1, z * 0.1, 4, 0.8, 2) * 7;
						if (h > 64 && w != 2) func(x, h, z, w * flag, arg);  // åñëè âûñîòà âûøå óðîâíÿ ìîðÿ è ýòî íå ìîðå - òî öâåòû, äåðåâüÿ â êîäå íèæå
					}
				}
				// trees
				int ok = SHOW_TREES;
				if (dx - 4 < 0 || dz - 4 < 0 ||
					dx + 4 >= CHUNK_SIZE || dz + 4 >= CHUNK_SIZE)
				{
					ok = 0;
				}
				if (ok && simplex2(x, z, 6, 0.5, 2) > 0.84) {
					for (int y = h + 3; y < h + 8; y++) {
						for (int ox = -3; ox <= 3; ox++) {
							for (int oz = -3; oz <= 3; oz++) {
								int d = (ox * ox) + (oz * oz) +
									(y - (h + 4)) * (y - (h + 4));
								if (d < 11) {
									if (h > 64 && w != 2) func(x + ox, y, z + oz, 15, arg);
								}
							}
						}
					}
					for (int y = h; y < h + 7; y++) {
						if (h > 64 && w != 2) func(x, y, z, 5, arg);
					}
				}
			}
			// clouds
			if (SHOW_CLOUDS) {
				for (int y = 100; y < 112; y++) {
					if (simplex3(
						x * 0.01, y * 0.1, z * 0.01, 8, 0.5, 2) > 0.75)
					{
						func(x, y, z, 16 * flag, arg);
					}
				}
			}*/
		}
	}
}
