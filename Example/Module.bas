Attribute VB_Name = "Module"
Option Explicit

Private Const CLIENT_XOR_KEY As Long = 192
Private Const SERVER_XOR_KEY As Long = 128

Private Client As Network.Client
Private Server As Network.Server

Private Function Create1stMessage() As Network.Writer
    Set Create1stMessage = New Network.Writer
    
    Call Create1stMessage.WriteInt(0)
    Call Create1stMessage.WriteString8("Hello, World")
End Function

Private Function Create2ndMessage() As Network.Writer
    Set Create2ndMessage = New Network.Writer
    
    Call Create2ndMessage.WriteInt(1)
    Call Create2ndMessage.WriteString8("Goodbye!")
End Function

Private Sub OnClientAttach()
    Debug.Print "OnClientAttach"
End Sub

Private Sub OnClientDetach(ByVal Code As Long)
    Debug.Print "OnClientDetach", Code
End Sub

Private Sub OnClientForward(ByVal Buffer As Network.Reader)
    Debug.Print "OnClientForward", Buffer.GetAvailable()
    
    Dim BufferRef() As Byte
    Call Buffer.GetData(BufferRef)
    
    Dim I As Long
    For I = 0 To UBound(BufferRef)
        BufferRef(I) = BufferRef(I) Xor CLIENT_XOR_KEY
    Next I
End Sub

Private Sub OnClientReceive(ByVal Buffer As Network.Reader)
    Debug.Print "OnClientReceive", Buffer.GetAvailable()

    Dim BufferRef() As Byte
    Call Buffer.GetData(BufferRef)
    
    Dim I As Long
    For I = 0 To UBound(BufferRef)
        BufferRef(I) = BufferRef(I) Xor SERVER_XOR_KEY
    Next I
    
    Select Case Buffer.ReadInt()
        Case 0
            Debug.Print "Create1stMessage", Buffer.ReadString8()
            Call Client.Send(False, Create2ndMessage())
    End Select
    
End Sub

Private Sub OnServerAttach(ByVal Connection As Long, ByVal Address As String)
    Debug.Print "OnServerAttach", Connection, Address
    
    Call Server.Send(Connection, False, Create1stMessage())
End Sub

Private Sub OnServerDetach(ByVal Connection As Long)
    Debug.Print "OnServerDetach", Connection
End Sub

Private Sub OnServerForward(ByVal Connection As Long, ByVal Buffer As Network.Reader)
    Debug.Print "OnServerForward", Connection, Buffer.GetAvailable()
    
    Dim BufferRef() As Byte
    Call Buffer.GetData(BufferRef)
    
    Dim I As Long
    For I = 0 To UBound(BufferRef)
        BufferRef(I) = BufferRef(I) Xor SERVER_XOR_KEY
    Next I
End Sub

Private Sub OnServerReceive(ByVal Connection As Long, ByVal Buffer As Network.Reader)
    Debug.Print "OnServerReceive", Connection, Buffer.GetAvailable()
        
    Dim BufferRef() As Byte
    Call Buffer.GetData(BufferRef)
    
    Dim I As Long
    For I = 0 To UBound(BufferRef)
        BufferRef(I) = BufferRef(I) Xor CLIENT_XOR_KEY
    Next I
    
    Select Case Buffer.ReadInt()
        Case 1
            Debug.Print "Create2ndMessage", Buffer.ReadString8()
  
            Call PrintStats("Client", Client.GetStatistics())
            Call PrintStats("Server", Server.GetStatistics(Connection))
    End Select
End Sub

Private Sub Main()
    Set Server = New Network.Server
    Set Client = New Network.Client
    
    Call Server.Attach(AddressOf OnServerAttach, AddressOf OnServerDetach, AddressOf OnServerForward, AddressOf OnServerReceive)
    Call Server.Listen(1, "0.0.0.0", "1000")
    
    Call Client.Attach(AddressOf OnClientAttach, AddressOf OnClientDetach, AddressOf OnClientForward, AddressOf OnClientReceive)
    Call Client.Connect("127.0.0.1", "1000")
    
    Do While (True)
        Call Server.Flush
        Call Server.Poll
        
        Call Client.Flush
        Call Client.Poll

        DoEvents
    Loop
End Sub

Private Sub PrintStats(ByVal Header As String, ByRef Stats As Network.Statistics)
    Debug.Print Header, "Bytes Sent", Stats.TotalBytesSent
    Debug.Print Header, "Bytes Received", Stats.TotalBytesReceived
    Debug.Print Header, "Bytes Pending", Stats.TotalBytesPending
    Debug.Print Header, "Messages Received", Stats.TotalPacketReceived
    Debug.Print Header, "Messages Sent", Stats.TotalPacketSent
End Sub
