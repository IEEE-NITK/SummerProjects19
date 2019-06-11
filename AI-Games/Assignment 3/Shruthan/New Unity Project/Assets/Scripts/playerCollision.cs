
using UnityEngine;

public class playerCollision : MonoBehaviour
{
    public PlayerScript movement;
    
    private void OnCollisionEnter(Collision collisioninfo)
    {
        
        if (collisioninfo.collider.tag == "Obstacle")
        {
            movement.enabled = false;
            FindObjectOfType<GameManager>().EndGame();

        }
    }
}
