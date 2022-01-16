from netmiko import ConnectHandler



Network_Device = { "host": "192.168.1.254",
                  "username": "cisco",
                  "password": "cisco",
                  "device_type": "cisco_ios",
                  "secret": "cisco",
}

Connect = ConnectHandler(**Network_Device)

Connect.enable()
#separation="##############################################"
#com1 = "Show ip interface s 3/"
interface = "interface s 3/"
ipaddress = "ip address 192.168.2."
commandas = [interface,ipaddress]
min=0
max=2
mask=" 255.255.255.0"
#for i in range(0,3):
#    print(Connect.send_command(com1+str(i)))
    
#print(separation)

##############FONCTION AJOUTER IP SUR UN INTERVALLE###################
def ajouterip(interface,ipaddress,mask,commandas,min,max) :
    for i in range (min,max):  #nbr max d'interfaces
        commandas[0]=interface+str(i) #de interface 0 à nbr max-1
        commandas[1]=ipaddress+str(i+1) #ip de .1 à nbr max
        for i in range (0,1):
            commandas[1]=commandas[1]+mask #ajoute mask to ip
            output = Connect.send_config_set(commandas)
            print(output)
            

ajouterip("interface s 3/","ip address 192.168.2.", " 255.255.255.0",[interface,ipaddress],0,2)


            
ajouterip("interface g 3/","ip address 192.168.4."," 255.0.0.0",[interface,ipaddress],0,4)




    


   


Connect.disconnect()

#output = Connect.send_config_set(commandas[i])
