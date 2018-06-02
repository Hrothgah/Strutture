#include <stdio.h>
#include <string.h>
#include "item.h"
#include "queue.h"

void instructions(void);

int main(void){
  Q coda = queueInit(100);
  int valore;
  char stringa[80];

  instructions();
  printf("%s", "? ");
  unsigned int scelta;
  scanf("%u", &scelta);

  while (scelta != 3){
    switch (scelta) {
      case 1:
        printf("%s", "Inserisci un intero: ");
        scanf("%d", &valore);
        queueEnqueue(coda, valore);
        break;
      case 2:
        if (!queueIsEmpty(coda)){
          printf("Il valore estratto e' %d\n",queueDequeue(coda));
        }
        break;
      case 4:
      puts("Benvenuto nel menu' segreto.\n"
           "Di quale personaggio di Infinity War vuoi che ti spoileri la morte?\n");
           scanf("%s", &stringa);
           printf("%s muore male.\n",stringa);
           puts("\n\n");
           instructions();
           break;
      case 5:
      printf("                                       `.--.``                                  UAI                 \n");
      printf("                                 `.-/+syyyyyyyso+/:`                             AR                 \n");
      printf("                               `/yyhhhhhhhhhhyyyyyyy+.                           U                  \n");
      printf("                             `+yhhhhhhhhhhhhhhyyyyyyyyo:`                        IR                 \n");
      printf("                           `/yhhhhhhhhhhhhhhhhhyyyyyyyyys/.                       ?                 \n");
      printf("                         `/yhhhhhhhhhhhhhhhhhhhhyyyyyyyyyyy+-                                       \n");
      printf("                        `sdhhhhhhhhhhhhhhhhyyyhhyyyyyyyyyyyyy/                                      \n");
      printf("                        ohhhhhhhhhhhhhhhhhhhhhhhhhhyyyyyyyyyhy.                                     \n");
      printf("                       -ddyssyhhhhhhhhhhhhhhhyyhhdyhhyyyyyyyyys`                                    \n");
      printf("                      /mMMN/`.:yhhhhhhhhhhhhshmNNdsos/ohyyyyyyh+                                    \n");
      printf("                      hMMMMmy..:hhysssyyyhhyoMMMMNmdmmshyyyyyyyy/                                   \n");
      printf("                    `.sdmmmmm/:/o/::::://++o/dmNNmNNmysyyyyyyyyyh:                                  \n");
      printf("                   `/////+++++oss::::::::::::://+////:://+yyyyhhhy`                                 \n");
      printf("           -oo++++++++///+/++sdmh/::::::://////////////:::yhhhhhyh/```````````                      \n");
      printf("         -ohhhhhhhhyyso+/////+++////////////////////////++yhhhhhhhhyssssssssssooo/`                 \n");
      printf("       `ohhhhhhhhhhhhhhhyo++///++++++++++/////////++osyyhhhhhhhhhhhhhhhhhhhhhhyyyhy+.               \n");
      printf("      `sdhhhhhhhhhhhhhhhhdhyo+++++///////////++++syhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhyyyo-`            \n");
      printf("     `ohdhys/:+dhhhhhhhhhhhddhs++++++++++++++osyhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhyyhs.           \n");
      printf("    `..:/..   .dhhhhhhhhhhhhdddhyyssooooossyhhdddhhhhhhhyhhhhhhhhhhhhhhhhhhhhhhhhhhhhhyhy-          \n");
      printf("   .-...--:`  `hhhhhhhhhhhhhdhhhhddmNmmmmmNNNNmdhhhhhdhhhhhhhhhhhhhhhhhhhhh.`-/oyyhhhhhhys.`        \n");
      printf("  `-....--.    yhhhhhhhhhhhhhhhhhdddmNNNNNNmdddhhhddddhhhhhhhhhhhhhhhhhhhhy       `.sho/-..`        \n");
      printf("  -.---::`     odhhhhhhhhhhdhhhhhdddddddddddddddhhhhhhhhhhhhhhhhhhhhhhhhhh+        `-/:-...``       \n");
      printf("  -.---::`     odhhhhhhhhhhdhhhhhdddddddddddddddhhhhhhhhhhhhhhhhhhhhhhhhhh+        `-/:-...``       \n");
      printf("  --...-`      /ddhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh-         `:/:-...``      \n");
      printf("   `           .hdhhhhhhhsoyhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh`         -//:--....`     \n");
      printf("                ydddhhhhhs.-/syhhhhhhhhhhhhhhhhhhhhhyshhhhhhhhhhhhhhhhhhhs           `.:::-...-.`   \n");
      printf("                /ddhhhhhhhs:---:+syhhhhhhhhhhhhhyyo+-/yyhhhhhhhhhhhhhhhhy.             ./:/-.  `-   \n");
      printf("                `ydhhhhhhhhhs:-----:/+osyssso+/:---/syyhhhhhhhhhhhhhhhhs.               -:::.       \n");
      printf("                 `odhhhhhhhhhhs/:----------------+syyhhhhhhhhhhhhhhhhhs`                   .-       \n");
      printf("                  `+dddhhhhhhhhhys+::------::/+syhhhhhhhhhhhhhhhhhhhh+`                             \n");
      printf("                    /hddddhhhhhhhhhyysssssyyyhhhhhhhhhhhhhhhhhhhhhy+.                               \n");
      printf("                     -oydddddhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhy/`                                 \n");
      printf("                       `-oddddddhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhy:`                                   \n");
      printf("                          sdddhhddddhhhhhhhhhhhhhhhhhhhhhhhhh:`                                     \n");
      printf("                          .hdhy.-:oyhdddddddddhdhdhhhhhhhhhhy                                       \n");
      printf("                          .yhhy`    `-/++o++/://////shhhhhhho                                       \n");
      printf("                          `shys`                    `:yhhhhy`                                       \n");
      printf("                         `/o+/+`                      +dhhh:                                        \n");
      printf("                       .+yyhy//                       +dhhy-                                        \n");
      printf("                      `yhyyhh:`                       oyyo/                                         \n");
      printf("                      `yhhhy:                        /so+//                                         \n");
      printf("                       `-::.                        +hshyy:                                         \n");
      puts("\n\n\n");
      printf("                                       DO U NO DA WAE?                                              \n");
      instructions();
      break;
      default:
        puts("Scelta non valida.\n");
        instructions();
        break;
    }
    printf("%s", "? ");
    scanf("%u", &scelta);
  }
  puts("Fine esecuzione.");
}

void instructions(void){
  puts("Effettua una scelta: \n"
       "1 per inserire un valore in coda\n"
       "2 per togliere un valore dalla coda\n"
       "3 per terminare il programma");
}
