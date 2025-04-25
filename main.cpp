#include <iostream>
#include <memory>
#include <vector>

class DeliveryCostCalculator {
public:
    virtual double calculateCost(double weight, double distance) const = 0;
    virtual ~DeliveryCostCalculator() = default;
};

// Стандартная доставка
class StandardDeliveryCalculator : public DeliveryCostCalculator {
    const double BASE_RATE = 5.0;
    const double RATE_PER_KG = 1.5;
    const double RATE_PER_KM = 0.1;

public:
    double calculateCost(double weight, double distance) const override {
        return BASE_RATE + (weight * RATE_PER_KG) + (distance * RATE_PER_KM);
    }
};

// Экспресс-доставка
class ExpressDeliveryCalculator : public DeliveryCostCalculator {
    const double BASE_RATE = 10.0;
    const double RATE_PER_KG = 2.5;
    const double RATE_PER_KM = 0.3;
    const double URGENCY_FEE = 15.0;

public:
    double calculateCost(double weight, double distance) const override {
        return BASE_RATE + (weight * RATE_PER_KG) + (distance * RATE_PER_KM) + URGENCY_FEE;
    }
};

// Международная доставка
class InternationalDeliveryCalculator : public DeliveryCostCalculator {
    const double BASE_RATE = 20.0;
    const double RATE_PER_KG = 5.0;
    const double RATE_PER_KM = 0.05;
    const double CUSTOMS_FEE = 30.0;

public:
    double calculateCost(double weight, double distance) const override {
        return BASE_RATE + (weight * RATE_PER_KG) + (distance * RATE_PER_KM) + CUSTOMS_FEE;
    }
};

int main() {
    std::vector<std::unique_ptr<DeliveryCostCalculator>> calculators;

    // Добавляем различные калькуляторы
    calculators.push_back(std::make_unique<StandardDeliveryCalculator>());
    calculators.push_back(std::make_unique<ExpressDeliveryCalculator>());
    calculators.push_back(std::make_unique<InternationalDeliveryCalculator>());

    // Пример расчета стоимости для посылки 5кг на 100км
    double weight = 5.0;
    double distance = 100.0;

    for (const auto& calculator : calculators) {
        double cost = calculator->calculateCost(weight, distance);
        std::cout << "Delivery cost: " << cost << std::endl;
    }

    return 0;
}