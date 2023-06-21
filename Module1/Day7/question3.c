#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100

struct LogEntry {
    int entryNo;
    char sensorNo[10];
    float temperature;
    int humidity;
    int light;
    char time[10];
};

void extractLogData(FILE* file, struct LogEntry* logEntries, int* numEntries) {
    char line[100];
    int entryIndex = 0;

    while (fgets(line, sizeof(line), file)) {
        char* token = strtok(line, ",");
        logEntries[entryIndex].entryNo = atoi(token);

        token = strtok(NULL, ",");
        strncpy(logEntries[entryIndex].sensorNo, token, sizeof(logEntries[entryIndex].sensorNo));

        token = strtok(NULL, ",");
        logEntries[entryIndex].temperature = atof(token);

        token = strtok(NULL, ",");
        logEntries[entryIndex].humidity = atoi(token);

        token = strtok(NULL, ",");
        logEntries[entryIndex].light = atoi(token);

        token = strtok(NULL, ",");
        strncpy(logEntries[entryIndex].time, token, sizeof(logEntries[entryIndex].time));

        entryIndex++;
    }

    *numEntries = entryIndex;
}

void displayLogData(const struct LogEntry* logEntries, int numEntries) {
    printf("EntryNo\tSensorNo\tTemperature\tHumidity\tLight\tTime\n");
    for (int i = 0; i < numEntries; i++) {
        printf("%d\t%s\t%.1f\t\t%d\t\t%d\t%s\n",
               logEntries[i].entryNo, logEntries[i].sensorNo, logEntries[i].temperature,
               logEntries[i].humidity, logEntries[i].light, logEntries[i].time);
    }
}

int main() {
    struct LogEntry logEntries[MAX_ENTRIES];
    int numEntries = 0;

    FILE* file = fopen("data.csv", "r");
    if (file == NULL) {
        printf("Failed to open the file.\n");
        return 1;
    }

    extractLogData(file, logEntries, &numEntries);

    printf("Log Data:\n");
    displayLogData(logEntries, numEntries);

    fclose(file);

    return 0;
}