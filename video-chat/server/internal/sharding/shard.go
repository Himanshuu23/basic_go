package sharding

import (
    "hash/fnv"
)

type Sharder struct {
    serverID  string
    totalShards int
}

func NewSharder(serverID string, totalShards int) *Sharder {
    return &Sharder{
        serverID:    serverID,
        totalShards: totalShards,
    }
}

func (s *Sharder) GetShardForRoom(roomID string) int {
    h := fnv.New32a()
    h.Write([]byte(roomID))
    return int(h.Sum32() % uint32(s.totalShards))
}

func (s *Sharder) IsResponsibleForRoom(roomID string, serverIndex int) bool {
    return s.GetShardForRoom(roomID) == serverIndex
}
