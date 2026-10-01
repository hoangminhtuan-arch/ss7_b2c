#include <stdio.h>

struct SmartDevice {
    int deviceID;
    char deviceName[50];
    int status;
    float ratedPowerKW;
};

struct EnergySensor {
    float voltageVolts;
    float currentAmperes;
    int unoccupancyMinutes;
};

int main() {
    struct SmartDevice device;
    struct EnergySensor sensor;

    float operatingHours;
    float totalKWh;
    float totalCost;

    printf("===== QUAN LY THIET BI SMART HOME =====\n");

    printf("Nhap ma thiet bi: ");
    scanf("%d", &device.deviceID);

    printf("Nhap ten thiet bi: ");
    scanf(" %[^\n]", device.deviceName);

    printf("Nhap trang thai (1-Bat, 0-Tat): ");
    scanf("%d", &device.status);

    printf("Nhap cong suat dinh muc (kW): ");
    scanf("%f", &device.ratedPowerKW);

    printf("\n===== THONG TIN CAM BIEN =====\n");

    printf("Nhap dien ap (V): ");
    scanf("%f", &sensor.voltageVolts);

    printf("Nhap dong dien (A): ");
    scanf("%f", &sensor.currentAmperes);

    printf("Nhap thoi gian vang nguoi (phut): ");
    scanf("%d", &sensor.unoccupancyMinutes);

    if (sensor.voltageVolts < 0 ||
        sensor.currentAmperes < 0 ||
        sensor.unoccupancyMinutes < 0) {

        printf("\nLOI: Du lieu cam bien khong hop le!\n");
        printf("Dien ap, dong dien va thoi gian vang nguoi khong duoc am.\n");

        return 0;
    }

    if (device.ratedPowerKW < 0) {
        printf("\nLOI: Cong suat dinh muc khong hop le!\n");
        return 0;
    }

    if (sensor.currentAmperes > 30.0f) {
        device.status = 0;

        printf("\n!!! CANH BAO QUA TAI !!!\n");
        printf("Dong dien: %.2f A > 30.0 A\n",
               sensor.currentAmperes);
        printf("Nguy co chay no!\n");
        printf("Thiet bi da duoc tu dong ngat dien.\n");
    }

    else if (device.status == 1 &&
             sensor.unoccupancyMinutes >= 15) {

        device.status = 0;

        printf("\nCANH BAO: Phong vang nguoi %d phut.\n",
               sensor.unoccupancyMinutes);
        printf("Thiet bi da duoc tu dong tat de tiet kiem nang luong.\n");
    }

    printf("\n===== TINH TIEN DIEN =====\n");

    printf("Nhap so gio van hanh trong thang: ");
    scanf("%f", &operatingHours);
    if (operatingHours <= 0 || operatingHours > 744) {

        printf("\nLOI: Thoi gian van hanh khong hop le!\n");
        printf("So gio phai lon hon 0 va khong vuot qua 744 gio.\n");

        return 0;
    }

    totalKWh = device.ratedPowerKW * operatingHours;

    if (totalKWh <= 50) {
        totalCost = totalKWh * 1806;
    } else if (totalKWh <= 100) {
        totalCost = 50 * 1806
                  + (totalKWh - 50) * 1866;
    } else if (totalKWh <= 200) {
        totalCost = 50 * 1806
                  + 50 * 1866
                  + (totalKWh - 100) * 2167;
    } else {
        totalCost = 50 * 1806
                  + 50 * 1866
                  + 100 * 2167
                  + (totalKWh - 200) * 2729;
    }

    printf("\n============================================\n");
    printf("       BAO CAO HE THONG SMART HOME\n");
    printf("============================================\n");

    printf("Ma thiet bi: %d\n", device.deviceID);
    printf("Ten thiet bi: %s\n", device.deviceName);
    printf("Cong suat dinh muc: %.2f kW\n",device.ratedPowerKW);
    printf("Dien ap: %.2f V\n",
           sensor.voltageVolts);
    printf("Dong dien: %.2f A\n",
           sensor.currentAmperes);
    printf("Thoi gian vang nguoi: %d phut\n",
           sensor.unoccupancyMinutes);
    printf("Trang thai thiet bi: %s\n",
           device.status == 1 ? "BAT" : "TAT");
    printf("So gio van hanh: %.2f gio\n",
           operatingHours);
    printf("Tong dien nang tieu thu: %.2f kWh\n",
           totalKWh);
    printf("Tong tien dien truoc VAT: %.0f VND\n",
           totalCost);
    printf("============================================\n");

    return 0;
}