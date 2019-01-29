#ifndef LCMSUBSCRIBER_HHH 
#define LCMSUBSCRIBER_HHH 
template<typename Callback_t>
class LCMSubscriber : public Subscriber<Callback_t> {
public:
    LCMSubscriber(std::shared_ptr<lcm::LCM> entity) :
        _subscribe_method(entity) {}


    void subscribe(const std::string& channel, const Callback_t& callback) {
        assert(! channel.empty());
        _subscribe_method -> subscribeFunction(channel, callback, 0);
        _subscribe_method->handle();
    }

    ~LCMSubscriber() {}

private:
    std::shared_ptr<lcm::LCM> _subscribe_method;
};

#endif //LCMSUBSCRIBER_HHH 
