#include <stdio.h>

//switch-case 문 (선택문)
// 정수값의 변화에따라서 분기 처리할때.

// 0:TV On, 1: TV Off, 2: Volume Up, 3: Volume Down
// 4: Channel Up, 5: Channel Down

// 열거형
enum ControlNum {
    TVON,
    TVOFF,
    VOLUMEUP,
    VOLUMEDOWN,
    CHANNELUP,
    CHANNELDOWN
};

int main() {
    int buttonNum = 0;   // 버튼 번호 입력

    printf("컨트롤 번호를 입력하세요: ");
    scanf_s("%d", &buttonNum);

    switch (buttonNum) {
    case TVON:
        printf("TV On\n");
        break;

    case TVOFF:
        printf("TV Off\n");
        break;

    case VOLUMEUP:
        printf("Volume Up\n");
        break;

    case VOLUMEDOWN:
        printf("Volume Down\n");
        break;

    case CHANNELUP:
        printf("Channel Up\n");
        break;

    case CHANNELDOWN:
        printf("Channel Down\n");
        break;

    default:   // 생략 가능
        printf("Wrong Number\n");
        break;

    }

    if (buttonNum == TVON) {

    }
    else if (buttonNum == TVOFF) {

    }


    return 0;
}