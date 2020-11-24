#include "valetparking.hpp"

// ATTENTION STUDENTS:
// THE CONSTRUCTORS ARE ALREADY COMPLETED.
// YOU NEED TO COMPLETE THE DESTRUCTOR AND ALL OF THE REMAINING FUNCTIONS BELOW.

// CONSTRUCTORS - ALREADY COMPLETE
ValetParking::ValetParking() : _numberofstalls( 1 ), _stallcapacity( 1 ), _queuecapacity( 1 ), _currentticket( 0 ),
    _fee( 5.0 ), _paid( 0.0 ), _checkout(new std::queue<size_t>()), _parkingstall(_numberofstalls, std::stack<size_t>() )
{}

ValetParking::ValetParking( size_t numberofstalls, size_t stallcapacity,
    size_t queuecapacity, size_t ticketnumber, double fee ) : _numberofstalls( numberofstalls ), _stallcapacity( stallcapacity ), _queuecapacity( queuecapacity ), _currentticket( ticketnumber ),
    _fee( fee ), _checkout(new std::queue<size_t>()), _parkingstall(_numberofstalls, std::stack<size_t>() ), _paid( 0.0 )
{}

// DESTRUCTOR
ValetParking::~ValetParking()
{
}

size_t ValetParking::totalStallSpaces()
// return the maximum number of cars that all stalls can accommodate
{

   return _numberofstalls *_stallcapacity;    // add by Chris Huynh

}

size_t ValetParking::carsInStalls()
// return the number of cars parked in all the stalls
{

    size_t totalCars = 0;
    for (const auto&s: _parkingstall)
    {
        totalCars += s.size();  // add by Chris Huynh
    }
    return totalCars;           // add by Chris Huynh

}

size_t ValetParking::carsInCheckOut()
// return the number of cars waiting in checkout line to pay before exiting the lot.
{

    return _checkout->size();     // add by Chris Huynh

}

size_t ValetParking::availableStallSpaces()
// return the number of available parking spaces in all the stalls
{

    size_t availableSpaces = 0;
    for (const auto&s: _parkingstall)
    {
        availableSpaces += (_stallcapacity - s.size());    // add by Chris Huynh
    }
    return availableSpaces;                // add by Chris Huynh

}

double ValetParking::totalSales()
// return the total amount based on the number of tickets issued
{

    return _currentticket * _fee;       // add by Chris Huynh

}

size_t ValetParking::pay()
// remove and return the ticket# of car at front of the checkout queue, and the fee is collected.
{

    if (_checkout->empty())
        return 0;
    _paid += _fee;
    size_t ticketNo = _checkout->front();
    _checkout->pop();
    return ticketNo;
    
    // add by Chris Huynh

}

double ValetParking::totalPaid()
// return the total amount customers have paid so far based on the number of cars exited the lot.
{

    return _paid;   // add by Chris Huynh

}

bool ValetParking::parkingEmpty()
// return true if all stalls and checkout queue are empty
{

    // ADD YOUR CODE HERE

}

bool ValetParking::parkingFull()
// return true if all stalls and checkout queue are full
{

    return StallEmpty() && QueueEmpty();
    
    // add by Chris Huynh

}

bool ValetParking::queueEmpty()
// return true if the checkout queue is empty
{

   return StallFull() && QueueFull();
    
    // add by Chris Huynh

}

bool ValetParking::queueFull()
// return true if the checkout queue is full
{

    
    return _checkout->size() == _queuecapacity;
    
    // add by Chris Huynh

}

bool ValetParking::stallEmpty()
// return true if all stalls are empty
{
     return _checkout->empty();
    
    // add by Chris Huynh


}

bool ValetParking::stallFull()
// return true if all stalls are full
{

    for (const auto&s : _parkingstall)
    {
        if (!s.empty())
            return false;
    }
    return true;
    
    // add by Chris Huynh

}

size_t ValetParking::getNextTicket()
// return the next ticket number to issue to customer
{
    return ++ _currentticket;
    
    // add by Chris Huynh

    

}

size_t ValetParking::checkIn()
// on success return stall# (index-1 base), on failure return 0.
{

   if (StallFull())
       return 0;
    size_t ticietNo = GetNextTicket();
    for (size_t i=0; i < _numberofstalls; i++)

}

size_t ValetParking::stallNumber( size_t ticket)
// return the stall number (index-1 base) in which the ticket number resides
{

   
    for (size_t i = 0; i < _numberofstalls; i++)
    {
        auto tmp = _parkingstall[i];
        while (!tmp.empty())
        {
            size_t ticketNumber == tmp.top();
            if (ticketNumber == ticket)
                return i + 1;
            tmp.pop();
            
            // add by Chris Huynh

}

bool ValetParking::checkOut( size_t stallnumber, size_t ticket) 
// Retrieve the ticket# from the stall and place the ticket in the checkout queue.
// On success return true.
{

    for (size_t i = 0; i < _numberofstalls; i++)
    {
        auto tmp = _parkingstall[i];
        while (!tmp.empty())
        {
            size_t ticketNumber == tmp.top();
            if (ticketNumber == ticket)
                return i + 1;
            tmp.pop();
            
            // add by Chris Huynh

}
