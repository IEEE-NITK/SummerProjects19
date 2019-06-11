using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PlayerScript : MonoBehaviour
{
    
    // Reference to rigid body component Rb
    public Rigidbody Rb;
    public float ForwardForce = 1000f;
    public float sidewaysForce = 500f;

    // Start is called before the first frame update

    void Start()
    {
        //Rb.useGravity = false;
        //Rb.AddForce(0, 200, 500);
        
    }

    // Update is called once per frame
    void Update()
    {
        // Add a forward force
        Rb.AddForce(0, 0, ForwardForce * Time.deltaTime);

        if (Input.GetKey("d"))
        {
            Rb.AddForce(sidewaysForce * Time.deltaTime, 0, 0, ForceMode.VelocityChange);
        }
        if (Input.GetKey("a"))
        {
            Rb.AddForce(-sidewaysForce * Time.deltaTime, 0, 0, ForceMode.VelocityChange);
        }
        if (Rb.position.y < -1f)
        {
            FindObjectOfType<GameManager>().EndGame();
            
        }
    }
}
