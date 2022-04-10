#ifndef  __09AGENDA_H__
#define  __09AGENDA_H__
typedef struct {
   int time;
   char buf[20];
} item;
item *read(item*);
void write(const item*);
#endif //__09AGENDA_H__
