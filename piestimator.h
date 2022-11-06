#ifndef PIESTIMATOR_H
#define PIESTIMATOR_H

#include <iostream>
#include <random>
#include <cmath>
#include <ctype.h>

class PiEstimator
{
public:
    PiEstimator();
    PiEstimator(int amountSamplesSetter);
    ~PiEstimator();

    void clear();

    void estimate_pi();
    double random_number_generator(double minValue, double maxValue);
    bool circle_checker(double xSample, double ySample, double maxValue);

    void set_amount_samples(int amountSamplesSetter);
    int get_amount_samples();
    void set_random_value_vectors(double randomXValue, double randomYValue);
    double get_final_pi_estimation();
    double get_estimated_values(int value);
    int get_darts_landed(int dart);
    int get_amount_darts_landed();

    std::vector<double> get_x_values();
    std::vector<double> get_y_values();
    std::vector<double> get_estimated_values();

protected:
    double maxValue{150};
    double minValue{-150};
    double dartsLanded{0};
    double estimatedValue{0};
    int amountSamplesProtected{0};

    std::vector<double> randomXValues;
    std::vector<double> randomYValues;
    std::vector<double> intermediateEstimatedValues;
    std::vector<int> amountTimesSampled;
    std::vector<int> amountDartsLanded;

};

#endif // PIESTIMATOR_H
