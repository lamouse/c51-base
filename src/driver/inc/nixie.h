#ifndef LED_SEGMENT_DISPLAYS_H
#define LED_SEGMENT_DISPLAYS_H

void show_index_num(char index, char num);

void show_num(int num);
void nixie_loop();
void nixie_scan(char index, char num);
void nixie_clear(char index);
void nixie_clear_all();
#endif