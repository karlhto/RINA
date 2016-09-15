#include "FailureSimulation.h"

FailureSimulation * FailureSimulation::instance = nullptr;

Define_Module(FailureSimulation);


void FailureSimulation::initialize() {
    FailureSimulation::instance = this;


    killTimer = new cMessage("Kill Time");
    resurrectTimer = new cMessage("Resurrect Time");


    c = par("amount").longValue();
    double tK = par("killAt").doubleValue();
    double tR = par("resurrectAt").doubleValue();

    if(c > 0 && tK > simTime().dbl()) {
        scheduleAt(tK, killTimer);
        if(tK < tR) {
            scheduleAt(tR, resurrectTimer);
        }
    }
}

void FailureSimulation::finish(){
    cancelAndDelete(killTimer);
    cancelAndDelete(resurrectTimer);
}

void FailureSimulation::handleMessage(cMessage * msg) {
    if(msg == killTimer) {
        if(alive.size() <= c) {
            cout << simTime() <<" - Kill all " <<alive.size()<<endl;
            for(auto & link : alive) {
                for(auto m : link2Nodes[link]) {
                    m->killLink(link);
                }
                dead.insert(link);
                cout << "-- "<< link <<endl;
            }
            dead.clear();
        } else {
            cout << "Kill "<< c <<endl;
            for(unsigned int i = 0; i < c ; i++) {
                auto it = alive.begin();
                advance(it, intuniform(0, alive.size()));
                string link = *it;
                for(auto m : link2Nodes[link]) {
                    m->killLink(link);
                }
                dead.insert(link);
                alive.erase(link);
                cout << "-- "<< link <<endl;
            }
        }
    } else if (msg == resurrectTimer) {
        for(auto & link : dead) {
            for(auto m : link2Nodes[link]) {
                m->resurrectLink(link);
            }
            alive.insert(link);
        }
        dead.clear();
    }
}

void FailureSimulation::registerLink(const string & link, FailureNode * owner) {
    alive.insert(link);
    link2Nodes[link].push_back(owner);
}