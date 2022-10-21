// C++ code

float beta;
float alpha;
float x[100];
float y[100];

void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
  for (int i = 0; i < 100; i++)
  {
    x[i] = i;
    y[i] = i * 0.5 + 1 + random(-1000, 1001) / 10000.;
  }
  Serial.begin(9600);

  float x_mean = 0;
  float y_mean = 0;
  for (int i = 0; i < 100; i++)
  {
  	x_mean = x_mean + x[i];
    y_mean = y_mean + y[i];
  }
  x_mean = x_mean / 100;
  y_mean = y_mean / 100;

  float cov = 0;
  float var_x = 0;

  for (int i = 0; i < 100; i++)
  {
  	cov = cov + (x[i] - x_mean) * (y[i] - y_mean);
    var_x = var_x + pow((x[i] - x_mean), 2);
  }

  beta = cov / var_x;
  alpha = y_mean - (beta * x_mean);
  Serial.print("mean x = ");
  Serial.println(x_mean);

  Serial.print("mean y = ");
  Serial.println(y_mean);

  Serial.print("alpha = ");
  Serial.println(alpha);

  Serial.print("beta = ");
  Serial.println(beta);


 
}





void loop(){}