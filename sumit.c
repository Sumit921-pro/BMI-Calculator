#include <stdio.h>
float getWeight();
void getHeight(float *feet, float *inches);
float convertHeightToMeters(float feet, float inches);
float calculateBMI(float weight, float heightInMeters);
void displayBMICategory(float bmi);

int main() {
    float weight = getWeight();
    float feet, inches;
    getHeight(&feet, &inches);
    float heightInMeters = convertHeightToMeters(feet, inches);
    float bmi = calculateBMI(weight, heightInMeters);

    printf("\nYour BMI is: %.2f\n", bmi);
    displayBMICategory(bmi);

    return 0;
}

float getWeight() {
    float weight;
    printf("Enter your weight in kilograms: ");
    scanf("%f", &weight);
    return weight;
}

void getHeight(float *feet, float *inches) {
    printf("Enter your height -\n");
    printf("Feet: ");
    scanf("%f", feet);
    printf("Inches: ");
    scanf("%f", inches);
}

float convertHeightToMeters(float feet, float inches) {
    const float inchesToMeters = 0.0254;
    const float feetToMeters = 0.3048;
    return (feet * feetToMeters) + (inches * inchesToMeters);
}

float calculateBMI(float weight, float heightInMeters) {
    return weight / (heightInMeters * heightInMeters);
}

void displayBMICategory(float bmi) {
    printf("Category: ");
    if (bmi < 18.5) {
        printf("Underweight\n");
    } else if (bmi >= 18.5 && bmi < 24.9) {
        printf("Normal weight\n");
    } else if (bmi >= 25 && bmi < 29.9) {
        printf("Overweight\n");
    } else {
        printf("Obese\n");
    }
}