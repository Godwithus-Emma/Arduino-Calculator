 
  double Prompt(String prompt){
    Serial.println(prompt);
    while(Serial.available()==0);
    String line = Serial.readString();
    line.trim();
    double value = line.toDouble();
    return value;
  }
  
  String PromptString(String prompt){
    Serial.println(prompt);
    while(Serial.available()==0);
    String line = Serial.readString();
    line.trim();
    String value= line;
    return value;
  }
  
  String formatDouble(double val){
    String value(val);
    //Serial.println("JJ "+ value);
    while (true)
    {
      int length = value.length();
       //Serial.println("length=" + String(length));
      char c = value[length-1];
      //Serial.println("c=" + String(c));
      if (c=='0' || c=='.' )
        {
          value = value.substring(0, length-1);
          //Serial.println("sub-value=" + value);
          if(c=='.'){
            break;
          }
        }
        else
        {
          break;
        }
    }
    return value;
  }
  //abc.00 6 0
  //abc.0 5 0
//abc. 4 0
  double addNumbers(double firstNumber, double secondNumber){
    return firstNumber + secondNumber;
  }
    double subtractNumbers(double firstNumber, double secondNumber){
    return firstNumber - secondNumber;
  }
  double multiplyNumbers(double firstNumber, double secondNumber){
    return firstNumber * secondNumber;
  }
    double divideNumbers(double firstNumber, double secondNumber){
    return  firstNumber / secondNumber;
  }
  
  void setup() {
Serial.begin(115200);

  

  
}

void loop() {
  double firstNumber= Prompt("Enter your first number");
  String operand= PromptString("Please enter an operator, (+, -, *, /)");
  double secondNumber = Prompt("Enter your second number");
  double result;
 if(operand=="+"){
  result = addNumbers(firstNumber, secondNumber);
  
 }
 else if(operand=="-"){
  result= subtractNumbers(firstNumber, secondNumber);
 }
 else if(operand=="*"){
  result = multiplyNumbers(firstNumber, secondNumber);
 }
 else if(operand=="/"){
  result = divideNumbers(firstNumber, secondNumber);
 }
 else{
    Serial.println("Please enter a valid operator");
    return;
  }
 // String res(result);
//Serial.print("Your answer = " + res);
Serial.print(formatDouble(firstNumber) +  operand +  formatDouble(secondNumber) + " = ");
Serial.println(formatDouble(result));
 }