#include "arduino_facture.h"

arduino_facture::arduino_facture()
{
    data2="";
    arduino_port_name="";
    arduino_is_available=false;
    serial=new QSerialPort;
}
QString arduino_facture::getarduino_port_name()
{
    return arduino_port_name;
}

QSerialPort *arduino_facture::getserial()
{
   return serial;
}
int arduino_facture::connect_arduino()
{   // recherche du port sur lequel la carte arduino identifÃ©e par  arduino_uno_vendor_id
    // est connectÃ©e
    foreach (const QSerialPortInfo &serial_port_info, QSerialPortInfo::availablePorts()){
           if(serial_port_info.hasVendorIdentifier() && serial_port_info.hasProductIdentifier()){
               if(serial_port_info.vendorIdentifier() == arduino_uno_vendor_id && serial_port_info.productIdentifier()
                       == arduino_uno_producy_id) {
                   arduino_is_available = true;
                   arduino_port_name=serial_port_info.portName();
               } } }
        qDebug() << "arduino_port_name is :" << arduino_port_name;
        if(arduino_is_available){ // configuration de la communication ( dÃ©bit...)
            serial->setPortName(arduino_port_name);
            if(serial->open(QSerialPort::ReadWrite)){
                serial->setBaudRate(QSerialPort::Baud9600); // dÃ©bit : 9600 bits/s
                serial->setDataBits(QSerialPort::Data8); //Longueur des donnÃ©es : 8 bits,
                serial->setParity(QSerialPort::NoParity); //1 bit de paritÃ© optionnel
                serial->setStopBits(QSerialPort::OneStop); //Nombre de bits de stop : 1
                serial->setFlowControl(QSerialPort::NoFlowControl);
                return 0;
            }
            return 1;
        }
        return -1;
}

int arduino_facture::close_arduino()

{

    if(serial->isOpen()){
            serial->close();
            return 0;
        }
    return 1;


}


 QByteArray arduino_facture::read_from_arduino()
{
    if(serial->isReadable()){
         data2=serial->readAll(); //rÃ©cupÃ©rer les donnÃ©es reÃ§ues

         return data2;
    }
 }


int arduino_facture::write_to_arduino( QByteArray d)

{

    if(serial->isWritable()){
        serial->write(d);  // envoyer des donnÃ©s vers Arduino
    }else{
        qDebug() << "Couldn't write to serial!";
    }


}
