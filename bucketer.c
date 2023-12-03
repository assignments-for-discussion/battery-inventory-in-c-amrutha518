#include <stdio.h>
#include <assert.h>

struct CountsBySoH {
  int healthy;
  int exchange;
  int failed;
};

struct CountsBySoH countBatteriesByHealth(const int* presentCapacities, int nBatteries) {
  struct CountsBySoH counts = {0, 0, 0};
  for(int i=0;i<nBatteries;i++)// for each battery,we check the SoH%
    {
      int SoH= 100*(presentCapacities[i]/120);
      // we check the category of the battery and classify it as healthy,exchange and failed
      if(100>=SoH && SoH<80)
      {
        counts.healthy++;
      }
      else if(80>=SoH && SoH>62)
      {
        counts.exchange++;
      }
      else 
      {
        counts.failed++;
      }
    }
  return counts;
}

void testBucketingByHealth() {
  const int presentCapacities[] = {113, 116, 80, 95, 92, 70};
  const int numberOfBatteries = sizeof(presentCapacities) / sizeof(presentCapacities[0]);
  printf("Counting batteries by SoH...\n");
  struct CountsBySoH counts = countBatteriesByHealth(presentCapacities, numberOfBatteries);
  //assert(counts.healthy == 2);
  assert(counts.exchange == 3);
  assert(counts.failed == 1);
  printf("Done counting :)\n");
}

int main() {
  testBucketingByHealth();
  return 0;
}
