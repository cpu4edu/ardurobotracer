//--------------------------------------------------------------------------
//  演習用ロボトレーサ(ArduRobotracer), タイマーを使わないバージョン
//                                                       葉山清輝（熊本高専）  
// 2019.9.2-14 ver1.0 完成
//--------------------------------------------------------------------------
// スイッチ説明
// 赤：リセットボタン， 黄色：セットボタン， 青：スタートボタン

// 演習１　
// 連続回転サーボのオフセットを調整する． 
// サーボモータは 0-180 の値で回転する．
// 90が中央値で，これより大きいと正回転，小さいと逆回転
#define OFFSETL 90  // サーボモーターのオフセット
#define OFFSETR 90  // サーボモーターのオフセット 

// 演習２　
// モーターを回転させてみる.
// セットボタンで0-3までプログラムを選んでスタートボタンを押す（LEDに2進数表示）
//  0:前進，1:バック，2:右回転，3:左回転

// 演習３
//　スピードを変えてみる 
#define TSPD 10     // モーターテストプログラムの回転速度

// 演習４
// 真っ直ぐ走らないない時は，回転速度を補正する
#define KR 1.0      // 右モーターの回転速度の補正値
#define KL 1.0      // 左モーターの回転速度の補正値, 0.9とかに替えてみる

// 演習５
// ラインセンサの確認
// プログラム５を選んでスタートすると白線の位置がLEDとPCに出力される．
// 左端で－３，中央で０，右端で３になる．値が滑らかに変わるように次の演習でしきい値を調整

// 演習６
// 個々の光センサを調整する．
// プログラム４を選んでスタートすると，PCにセンサの値が表示される．(0～1023の範囲)
// センサ黒い板の上だと値が小さく，白線の上だと反射光により値が大きくなる．
// 白線の上だと判断する境目の値（しきい値）を修正する．
#define CTH   500   // コーナーマーカーのしきい値，SGマーカーより低くして，交差点の検出につかう．
#define SGTH  500   // スタート，ゴールマーカーのしきい値
#define S3TH  200   // センサ３のしきい値
#define S4TH  200   // センサ４のしきい値
#define S5TH  200   // センサ５のしきい値
#define S6TH  200   // センサ６のしきい値

// 演習７
// 速度可変のライントレース走行(フリーラン)
// プログラム６を選んでスタートするとライントレース走行を行う．
// 速度の初期値は１，セットボタンを押すたびに速度が増加する．速度はLEDに２進数で表示.
#define FR0VC  1   // 速度の初期値
#define FR0KP  3   // 比例係数の初期値
#define FR0KD  0   // 微分係数の初期値

// 演習８
// 比例係数可変のライントレース走行(フリーラン)
// プログラム７を選んでスタートするとライントレース走行を行う．
// 比例係数の初期値は１，セットボタンを押すたびに比例係数が増加する．比例係数はLEDに２進数で表示.
#define FR1VC  10  // 速度の初期値
#define FR1KP  1   // 比例係数の初期値
#define FR1KD  0   // 微分係数の初期値

// 演習９
// 微分係数可変のライントレース走行(フリーラン)
// プログラム８を選んでスタートするとライントレース走行を行う．
// 微分係数の初期値は０，セットボタンを押すたびに微分係数が増加する．微分係数はLEDに２進数で表示.
// ただし，原理通りに上手くはいかない．
#define FR2VC  10  // 速度の初期値
#define FR2KP  5   // 比例係数の初期値
#define FR2KD  0   // 微分係数の初期値

// 演習１０
// ライントレース競技走行，１回目
// プログラム９を選んでスタートすると競技走行を行う．
// 右側のスタートマーカーを検知して低いビープ音，
// 左側のコーナーマーカーを検知して高いビープ音，
// 交差点はマーカーを無視して直進，
// ゴールマーカーを検知して0.5秒後にストップ.
// 安全にゴールできる速度での安定走行を狙う．
#define CR1VC  10  // 速度の初期値
#define CR1KP  2   // 比例係数の初期値
#define CR1KD  0   // 微分係数の初期値

// 演習１１
// ライントレース競技走行，２回目
// プログラム１０を選んでスタートすると競技走行を行う．
// より高速にゴールを狙う．
#define CR2VC  15  // 速度の初期値
#define CR2KP  3   // 比例係数の初期値
#define CR2KD  1   // 微分係数の初期値

// 演習１２
// ライントレース競技走行，３回目
// プログラム１１を選んでスタートすると競技走行を行う．
// より高速にゴールを狙う．
#define CR3VC  20  // 速度の初期値
#define CR3KP  5   // 比例係数の初期値
#define CR3KD  2   // 微分係数の初期値

// 演習１３
// 高度な設定を行うことができる．
// 光センサを読み取る時間間隔を調整できる．高速走行ではセンサ読み取りが
// 間に合わない時がある.短すぎると誤動作するので注意．
#define SENSINT 5   // センサーのインターバル(ms)
// モーターの制御を行う時間間隔を調整できる．
// 機械的な動きに合わせて調整すると良くなる．早すぎてて遅すぎてもだめ．
#define CTRLINT 20  // 制御のインターバル(ms)
// マーカーの検出処理を繰り返す時間間隔を調整できる．誤作動を防ぐために適当な時間が必要．
#define LPINT 2     // ループのインターバル(ms)


// **************  これ以降はプログラム，書き換え不要　***************************

// ブザー -------------
#define BEEPH tone(BZ,1000,100)  // 1kHz
#define BEEPL tone(BZ,800,1000)  // 800Hz

// ピンアサイン----------
#define SET_SW    2     // セットスイッチ，デジタル入力
#define START_SW  3     // スタートスイッチ，デジタル入力 
#define LEDOUT1 8    //ラインセンサ用LED出力（）
#define LEDOUT2 9    //ラインセンサ用LED出力（）
#define MOTOR_L  5  // 連続回転サーボ出力L
#define MOTOR_R  6  // 連続回転サーボ出力R
#define BZ 7    //ブザー用出力
// センサ入力ピン番号
#define SENS_C  A0  // マーカーセンサ1,コーナーマーカー
#define SENS_SG A1  //  マーカーセンサ2,スタート・ゴールマーカー
#define SENS_34 A2  // ラインセンサ3,4
#define SENS_56 A3  // ラインセンサ5,6
#define GYRO_IN A4  // ジャイロセンサ
#define SENS_OP A5  // センサオプション

// 変数定義---------------
int pmode=0;           // プログラムモード(メインメニューで分岐)
volatile int sensC, sensCB;  // ラインセンサ右，赤外線点灯前（以下同様）
volatile int sensSG, sensSGB;  // ラインセンサ中央
volatile int sens3, sens3B;  // ラインセンサ左
volatile int sens4, sens4B;  // ラインセンサ左
volatile int sens5, sens5B;  // ラインセンサ左
volatile int sens6, sens6B;  // ラインセンサ左
volatile int ledSW=0;
volatile int sensD,sensDout,sensDoutB;
volatile int sensCtime=100;
volatile long tchange=0;

// センサ値->ライン位置の返還行列，index6が中央で0,それ以外も0，全センサOFFで99
const int sensArray[16]={99,3,1,2,-1,0,0,0,-3,0,0,0,-2,0,0,0};  

#include <Servo.h> 
Servo motorL;
Servo motorR;

//-------------------------------------------------------------------------- 
// 各種関数
//-------------------------------------------------------------------------- 

// LED表示 -------------------------------------------------------------- 	                                              	 
void dispLED(byte n)
{
 PORTB &= B11000011;                     // LEDを一旦消す
 PORTB |= (n<<2);                        // LED表示
}

//-------------------------------------------------------------------------- 
// 赤外線センサー読み取り，並列接続のセンサを左右交互に読み取る，2回読んで更新
void sensors() {
  
  // 赤外線LED消灯時のセンサの読み
  sensCB=analogRead(SENS_C);   
  sensSGB=analogRead(SENS_SG);
  sens3B=sens4B=analogRead(SENS_34);
  sens5B=sens6B=analogRead(SENS_56);
  
  // ledSWを反転しながら並列のセンサを交互に読む
  ledSW=!ledSW;
  if(ledSW){
    digitalWrite(LEDOUT1, HIGH);    // 赤外線LED点灯
    delayMicroseconds(20);         // ちょっと待つ
    sens3=analogRead(SENS_34)-sens3B;  // 赤外線点灯前後の差でラインの読みとする，以下同様
    sens5=analogRead(SENS_56)-sens5B;
    sensC=analogRead(SENS_C)-sensCB;
    digitalWrite(LEDOUT1, LOW);    // 赤外線LED消灯     
  } else {
    digitalWrite(LEDOUT2, HIGH);    // 赤外線LED点灯
    delayMicroseconds(20);         // ちょっと待つ
    sens4=analogRead(SENS_34)-sens4B;  // 赤外線点灯前後の差でラインの読みとする，以下同様
    sens6=analogRead(SENS_56)-sens6B;
    sensSG=analogRead(SENS_SG)-sensSGB;
    digitalWrite(LEDOUT2, LOW);    // 赤外線LED消灯
  }
  
  // 各センサのON-OFFをラインとの位置の整数値，－３から３までに変換
  sensD=0;
  if (sens3>S3TH ) sensD |= 0x08; else sensD &= ~(0x08);   
  if (sens4>S4TH ) sensD |= 0x04; else sensD &= ~(0x04);   
  if (sens5>S5TH ) sensD |= 0x02; else sensD &= ~(0x02);  
  if (sens6>S6TH ) sensD |= 0x01; else sensD &= ~(0x01);  
  sensDoutB=sensDout;          // 一つ前の値を保管
  sensDout=sensArray[sensD];   // 位置に変換
  // センサ値に変化が出るまでの時間をカウントする．微分制御に用いる
  if (sensDoutB != sensDout){  
    if(sensDoutB>sensDout) sensCtime=millis()-tchange; else sensCtime=tchange-millis();
    tchange=millis();
  }  
} 

//----------------------------------------------------------------------------------  
// テストプログラム 
//----------------------------------------------------------------------------------   
// 全赤外線センサテスト　-------------------------------------------  
void testSensors(){
  while(digitalRead(START_SW)==HIGH){
    
    // センサー読み取り
    sensors(); delay(25); 
    sensors(); delay(25); 
    // センサ値をシリアル出力
    Serial.print("C:");Serial.print(sensC); 
    Serial.print(" SG:");Serial.print(sensSG); 
    Serial.print(" PT3:");Serial.print(sens3);
    Serial.print(" PT4:");Serial.print(sens4); 
    Serial.print(" PT5:");Serial.print(sens5); 
    Serial.print(" PT6:");Serial.println(sens6);  
  }
}
// ライン位置の出力　-----------------------------------------
void testSensD(){
  while(digitalRead(START_SW)==HIGH){
    // センサー読み取り
    sensors(); delay(25); 
    sensors(); delay(25); 
    dispLED(sensD);
    // ライン位置をシリアル出力
    //Serial.print("D:"); Serial.print(sensD); 
    Serial.print("POS:"); Serial.println(sensDout);
  }
}

//---------モーターテスト----------------------------------------------------------
void testMotorF(){   // 前進
  motorL.write(OFFSETL+TSPD*KL); 
  motorR.write(OFFSETR-TSPD*KR);  
  delay(1000);
}
void testMotorB(){   // バック
  motorL.write(OFFSETL-TSPD*KL);  
  motorR.write(OFFSETR+TSPD*KR);  
  delay(1000);
}
void testMotorRturn(){   // 右ターン
  motorL.write(OFFSETL+TSPD*KL);  
  motorR.write(OFFSETR+TSPD*KR);   
  delay(1000);
}
void testMotorLturn(){   // 左ターン
  motorL.write(OFFSETL-TSPD*KL);  
  motorR.write(OFFSETR-TSPD*KR); 
  delay(1000);
}

//-------------------------------------------------------------------------- 
// フリーラン，パラメータ可変のライントレース
//-------------------------------------------------------------------------- 
void freeRun(int fm, float vC, float kP, float kD ){
// fm=0: 速度可変，fm=1: 比例係数可変，fm=2:微分係数可変
// vC:中心速度，　kP:比例係数，　kD:微分係数，　kI:積分係数(未使用)

float vp;
int vR,vL;
int frun=0;    // スタート，ゴールマーカーの処理のための状態遷移 
int markerC=0; // コーナーマーカー読み取り
int markerSG=0; // スタート・ゴールマーカー読み取り
long tms;    //　ゴールを超えて静止するまでの時間ms．
long tsens;  //　センサ読み取りの間隔の監視タイマー．
long tctrl;  //　制御の時間間隔の監視タイマー．

      tsens=tctrl=millis();  // タイマー初期化
      sensors(); delay(15); sensors(); delay(15); // センサー初期化
      if (fm==0) dispLED(vC); 
      if (fm==1) dispLED(kP); 
      if (fm==2) dispLED(kD); 
      
      while(digitalRead(START_SW)){
 
        if (digitalRead(SET_SW)==0){      // SETスイッチが押された時，パラメータを変える
          while(digitalRead(SET_SW)==0);  // SETを離すまで待つ
          if (fm==0){vC++; dispLED(vC); }
          if (fm==1){kP++; dispLED(kP); }
          if (fm==2){kD++; dispLED(kD); }  
        }
        
        // センサー読み取り
        if (millis()>(tsens+SENSINT)){
          tsens=millis();
          sensors();  // 片側ずつ読むので2回呼び出して全部更新される
        }
        // センサはずれたときはコースアウトとしてBEEP
        if (sensDout==99){ BEEPL; sensDout=0; }
        Serial.println(sensCtime);
        
        // モーター制御
        if (millis()>(tctrl+CTRLINT)){
          tctrl=millis();
          
          vp=(float)sensDout*kP-10.0/(float)sensCtime*kD;
          vR=(float)(OFFSETR-vC+vp)*KR;
          vR=constrain(vR,0,180);
          vL=(float)(OFFSETL+vC+vp)*KL;
          vL=constrain(vL,0,180);
        
          motorL.write(vL);
          motorR.write(vR);
        }
        
        delay(LPINT);  // マーカー処理のインターバル
    }

    // モータ停止 
    motorL.write(OFFSETL);
    motorR.write(OFFSETR); 
 }
 
//-------------------------------------------------------------------------- 
// ライントレース走行
// スタート・ゴールマーカー処理含む，コーナーマーカでビープ
//-------------------------------------------------------------------------- 
void run1(float vC, float kP, float kD ){
// vC:中心速度，　kP:比例係数，　kD:微分係数，　kI:積分係数(未使用)

float vp;
int vR,vL;
int frun=0;    // スタート，ゴールマーカーの処理のための状態遷移 
int markerC=0; // コーナーマーカー読み取り
int markerSG=0; // スタート・ゴールマーカー読み取り
long tms;    //　ゴールを超えて静止するまでの時間ms．
long tsens;  //　センサ読み取りの間隔の監視タイマー．
long tctrl;  //　制御の時間間隔の監視タイマー．

      tsens=tctrl=millis();  // タイマー初期化
      sensors(); delay(15); sensors(); delay(15); // センサー初期化
      
      while(digitalRead(START_SW)){
        
        // センサー読み取り
        if (millis()>(tsens+SENSINT)){
          tsens=millis();
          sensors();  // 片側ずつ読むので2回呼び出して全部更新される
        }
        
        // モーター制御
        if (millis()>(tctrl+CTRLINT)){
          tctrl=millis();
          
          vp=(float)sensDout*kP-10.0/(float)sensCtime*kD;
          vR=(float)(OFFSETR-vC+vp)*KR;
          vR=constrain(vR,0,180);
          vL=(float)(OFFSETL+vC+vp)*KL;
          vL=constrain(vL,0,180);
        
          motorL.write(vL);
          motorR.write(vR);
        }
        
        // センサはずれたときはコースアウトとして終了
        if (sensDout==99){ BEEPL; break; }
        
        // コーナーマーカー処理
        if (markerC==0 && sensC>CTH) markerC=1;     // コーナーマーカーに乗った時
        if (markerC==1 && sensSG>SGTH) markerC=2;   // その後スタートゴールマーカーに乗った時は交差点
        if (markerC==2 && sensC<CTH) markerC=0;     // 交差点なので処理なしでフラグを戻す
        if (markerC==1 && sensC<CTH) {              // コーナーマーカーを超えた時の処理
          markerC=0; 
          BEEPH;
          
        }
        
        // スタート・ゴールマーカー処理
        if (markerSG==0 && sensSG>SGTH) markerSG=1; // マーカーに乗った時
        if (markerSG==1 && sensC>CTH) markerSG=2;   // その後スタートゴールマーカーに乗った時は交差点
        if (markerSG==2 && sensSG<SGTH) markerSG=0; // 交差点なので処理なしでフラグを戻す
        if (markerSG==1 && sensSG<SGTH) {           // マーカーを超えた時の処理
          markerSG=0; 
          BEEPL;
          frun++;  // SGマーカー通過ごとに１足す
          if (frun==2) {frun=3; tms=millis(); BEEPL;} // 2回目がゴールなので停止のためのタイマーセット
        }
        if (frun==3 && millis()>(tms+500)) break;   // ゴールしたら0.5秒で停止
     
        delay(LPINT);  // マーカー処理のインターバル
    }

    // モータ停止 
    motorL.write(OFFSETL);
    motorR.write(OFFSETR); 
 }

//-------------------------------------------------------------------------- 
// セットアップ（最初に一度だけ実行）
//-------------------------------------------------------------------------- 
void setup()
{
  DDRB |=B00111111;      // PB0,1: センサLED，PB2-5: 表示用LEDで出力せってい,
                         // PB6,7はクリスタルなので入力設定
  pinMode(SET_SW, INPUT);
  pinMode(START_SW, INPUT);
  digitalWrite(SET_SW, HIGH);  
  digitalWrite(START_SW, HIGH);  
  
  pinMode(LEDOUT1, OUTPUT);
  pinMode(LEDOUT2, OUTPUT);
  digitalWrite(LEDOUT1, LOW);    // 赤外線LED消灯
  digitalWrite(LEDOUT2, LOW);    // 赤外線LED消灯

//  pinMode(BZ, OUTPUT);
//  digitalWrite(BZ, LOW);    // 赤外線LED消灯
  
  motorL.attach(MOTOR_L);
  motorR.attach(MOTOR_R);    
  motorL.write(OFFSETL);  
  motorR.write(OFFSETR);  
  
  // シリアル通信スタート
  Serial.begin(9600);   
}

//-------------------------------------------------------------------------- 
// ループ（繰り返し実行）
//-------------------------------------------------------------------------- 
void loop(){
  
  dispLED(pmode);                     // プログラムモードをLEDに2進表示  
  
  while (digitalRead(START_SW)==HIGH){   // スタートスイッチが押されたら指定プログラムを実行
    if (digitalRead(SET_SW)==LOW) {      // セットスイッチが押されたらプログラムモードを進める
      delay(10);                      // チャタリング防止
      while(digitalRead(SET_SW)==LOW);
      delay(10);                      // チャタリング防止
      pmode++; if (pmode>15) pmode=0;  // プログラムモードを一つ増やす
      dispLED(pmode);                 // プログラムモードをLEDに2進表示 
      BEEPH;
    }
  }  
  // スタートスイッチが押されたら処理プログラムへ分岐
  dispLED(0);
  delay(500);                         // 0.5秒待つ

  switch(pmode){                      // 選択されたプログラムモードのプログラムを実行
    case  0:  testMotorF(); break;
    case  1:  testMotorB(); break;
    case  2:  testMotorRturn(); break;
    case  3:  testMotorLturn(); break;  
    
    case  4:  testSensors(); break; // 全センサーのテスト    
    case  5:  testSensD(); break;  // センサ位置のテスト 

    case  6:  freeRun(0,FR0VC,FR0KP,FR0KD); break;  // フリーラン，速度可変のライントレース
    case  7:  freeRun(1,FR1VC,FR1KP,FR1KD); break; // フリーラン，比例係数可変のライントレース 
    case  8:  freeRun(2,FR2VC,FR2KP,FR2KD); break; // フリーラン，微分係数可変のライントレース 
    case  9:  run1(CR1VC,CR1KP,CR1KD); break;      // １回目 ライントレース走行（中心速度，比例係数，微分係数）
    case  10: run1(CR2VC,CR2KP,CR2KD); break;      // ２回目 ライントレース走行（中心速度，比例係数，微分係数）
    case  11: run1(CR3VC,CR3KP,CR3KD); break;      // ３回目 ライントレース走行（中心速度，比例係数，微分係数）
  } 
  motorL.write(OFFSETL);  
  motorR.write(OFFSETR);  
  delay(500);                         // 0.5秒待つ
}
