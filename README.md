# PhoenixSim
This project is a continuation of the project by Sergi Abadal. Any questions about the original code should be submitted to him. I made the following changes to simulate different security aspects of the WiNoC.
These include:
1. adding delay for both the sender encrypting the message and the receiver decrypting the message.
2. modifying the backoff delay of a node that attempts to gain more access to the network.
3. duplicating messages inside of a node to replicate a node that is busy with more traffic to send or attempting to flood the network.
4. created new MACAW protocol so that nodes learn the average number of backoffs to improve the backoff latency in the network.

##The following files have been altered:
*All line locations are approximate*

1. electronicComponents/MAC_Layer/MAC_BRS.h
   * Lines 68 - 197
Added variables for both collisions by node and discarded packets by node (Currently packets are only discarded if the queue is full at the node)
   * Lines 199 - 262
Added variables for the backoff time of the messages before able to send
   * Lines 264 - 327
Added variable to track the average time that a packet spends in the queue before it becomes head of the line
   * Line 53
Creates global variable for total_backoff

2. electronicComponents/MAC_Layer/MAC_BRS.cc
   * Lines 48 - 307
Added statistics for tracking collisions, discarded, backoff time, and queue time for packets by node
   * Line 335, 1201, & 685
Commented out nRetries @ 335 and 682, instead added to 684 to prevent backoff from reseting too often
   * Line 360 & 438
Changed from retries < 2 to retries < 2000 to prevent the node from attempting to send the message over the wired backbone
   * Lines 927 - 1119
Track the collisions by node
   * Line 1186
Changed MACqueue.size() > 1 to 1000 to test a node with many messages to send
   * Lines 1214 - 1406
Track nodes that discard messages when the queue is full
   * Lines 1427 - 1429
Checks to see if there is an unhealthy node(s) [idnum == ? ] and then sets the random backoff to a smaller number [clockPeriod]
   * Line 45 & 1430
Sets total_backoff to 0 and then tracks culmulative backoff time at line 1430.  
   * Lines 729 - 921
Tracks the total backoff time of a message before it successfully sends then resets total_backoff
   * Lines 491 = 682
Track total queue time before a packet becomes head of line

3. parameters/custom/Hybrid-Synthetic.ini
   * Line 17
Set numofNodesX to 8 for 8x8 mesh
   * Line 30
Set bcast percentage to 100% so that the network only uses the wireless
   * Lines 58 - 76
Set parameters for the Broadcast CBUF network to include saturation throughputs for different network bandwidths at 1GHz, 100% short messages, and change to appParam9
   * Lines 201 - 210
Small changes to the parameters for the Broadcast CSMA hybrid
   * Lines 219 -220
Line 220 is the orginal naming convention for the statistics files. Changed to line 219 for brevity in these experiments.
   * Lines 331 - 367
Creates a different run that will run the MACAW protocol in the simulator

4. parameters/default/eNework.ini
   * Line 6
Changed processor frequency to 1GHz

5. processingPlane/Processor.h
   * Lines 84 - 211
Added variables for number of messages sent (SO_num_messages_XX) and broadcast latency (SO_latency_bcast_XX) by node (0 - 63)

6. processingPlane/Processor.cc
   * Lines 242 - 370
Create the statistics to log the number of messages sent and the broadcast latency by node (0 - 63)
   * Lines 662 - 924
Tracks the latency and number of packets sent by a node by checking the destination address against the receiving node. If true, checks the source address and records appropriate statistic. (Only nodes 0-63)

7. processingPlane/interfaces/wNIF.h
   * Line 128
Declare a double for encryption delay
   * Line 130
Declare a double for the delay of sending the token to the next node

8. processingPlane/interfaces/wNIF.cc
   * Lines 61 - 62
These variables allow for changing the encryption delay (at both sender and receiver) and the delay for passing a token (at the sender) without going further in the code
   * Lines 246 - 274
Allows for the manipulation of the number of messages sent by particular nodes. Adds X messages to the queue of the node(s) and sets the creation time of messages to the current time to prevent issues with the message latency
   * Line 514
Send the message to the MAC module with the delay for passing the token and encryption delay
   * Line 610
Sends the message to the processor with the encryption delay

9. statistics/statistics.cc
   * Lines 47 - 55
Moved stats for the malicious tests to the top of the results
   * Lines 133 - 135
Created a MMA statistic to collect the queue time and backoff times

10. electronicComponents/MAC_Layer/MAC_MACAW.ned
   * Entire file
ned file for new MACAW protocol

11. electronicComponents/MAC_Layer/MAC_MACAW.cc
   * Entire file
C++ file for new MACAW protocol

12. electronicComponents/MAC_Layer/MAC_MACAW.h
   * Entire file
header file for new MACAW protocol

13. simCore/messages.msg
   * Line 112
Added line for BOcounter to be included in the message to create MACAW protocol
