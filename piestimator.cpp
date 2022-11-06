#include "piestimator.h"

PiEstimator::PiEstimator()
{
}

PiEstimator::PiEstimator(int amountSamplesSetter)
{
    set_amount_samples(amountSamplesSetter);
    estimate_pi();
}

PiEstimator::~PiEstimator()
{
    clear();
}

void PiEstimator::clear()
{
    randomXValues.clear();
    randomYValues.clear();
    intermediateEstimatedValues.clear();
    amountTimesSampled.clear();
    amountDartsLanded.clear();
    amountSamplesProtected = 0;
    dartsLanded = 0;
    estimatedValue = 0;

}

void PiEstimator::estimate_pi()
{
    if(amountSamplesProtected != 0)
    {
        for (int i = 1; i <= amountSamplesProtected; ++i)
        {
            double xSample{random_number_generator(minValue,maxValue)};
            double ySample{random_number_generator(minValue,maxValue)};

            set_random_value_vectors(xSample, ySample);

            if (circle_checker(xSample,ySample,maxValue))
            {

                ++dartsLanded;
                estimatedValue = 4 * (dartsLanded/i);
                amountDartsLanded.push_back(i);
                intermediateEstimatedValues.push_back(estimatedValue);
            }
        }
    }
}

void PiEstimator::set_amount_samples(int amountSamplesSetter)
{
    amountSamplesProtected = amountSamplesSetter;
}

int PiEstimator::get_amount_samples()
{
return amountSamplesProtected;
}

void PiEstimator::set_random_value_vectors(double randomXValue, double randomYValue)
{
    randomXValues.push_back(randomXValue);
    randomYValues.push_back(randomYValue);
}

std::vector<double> PiEstimator::get_x_values()
{
    return randomXValues;
}

std::vector<double> PiEstimator::get_y_values()
{
    return randomYValues;
}

std::vector<double> PiEstimator::get_estimated_values()
{
    return intermediateEstimatedValues;
}


double PiEstimator::get_final_pi_estimation()
{
    return estimatedValue;
}

double PiEstimator::get_estimated_values(int value)
{
    return intermediateEstimatedValues[value];
}

int PiEstimator::get_darts_landed(int dart)
{
    return amountDartsLanded[dart];
}

int PiEstimator::get_amount_darts_landed()
{
    return amountDartsLanded.size();
}

double PiEstimator::random_number_generator(double minValue, double maxValue)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(minValue, maxValue);
    return dis(gen);
}

bool PiEstimator::circle_checker(double xSample, double ySample, double maxValue)
{
    double radiusChecker {sqrt((xSample*xSample) + (ySample*ySample))};
    if (radiusChecker < maxValue)
    {
        return true;
    }
    else
    {
        return false;
    }
}



