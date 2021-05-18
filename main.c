#include <stdio.h>
#include <stdlib.h>
#include <linux/i2c.h>
#include <linux/i2c-dev.h>
#include <sys/ioctl.h>
#include <stdint.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main(){
        printf("i2c scanner \n");
        FILE* i2cDevices = popen("ls /dev/i2c*","r");
        if(i2cDevices == NULL){
                printf("There is no i2c device!\n");
                return 0;
        }
        char deviceName[100];
        char deviceNames[100][100];
        char i=0;
        while(fgets(deviceName,sizeof(deviceName),i2cDevices)!=NULL){
                printf("%d) %s",i,deviceName);
                for(int j=0;j<100;j++){
                        if(deviceName[j] == '\n'){
                                deviceName[j] = '\0';
                                break;
                        }
                }
                strcpy(deviceNames[i],deviceName);
                i++;
        }
        pclose(i2cDevices);
        int select;
        printf("Select an device : ");
        scanf("%d",&select);

        int i2c = open(deviceNames[select], O_RDWR);
        if(i2c < 0){
                printf("Error open %d %s\n",strlen(deviceNames[select]),deviceNames[select]);
                return 0;
        }
        char testData[] = {0};
        for(int i=0;i<=127;i++){
                int f = ioctl(i2c,I2C_SLAVE,i);
                if(f>=0){

                        int res = write(i2c,testData,1);
                        if(res<0){
                                //printf("%d\n",i);
                        }else{
                                printf("finded 0x%X\n",i);
                        }
                }else{
                        //printf("err %d\n",i);
                }
        }

        close(i2c);
        return 0;
}
